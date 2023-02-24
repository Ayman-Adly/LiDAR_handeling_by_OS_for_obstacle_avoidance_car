'''
@file:   python script to fetch data from LiDAR and communicated to AVR target by SPI
@author: Ayman El Tanboly (and) Hisham Montaser
@version: 3.2
@date: 16/2/2023
'''
#library for SPI connection For RPI
import spidev
#library for using time delay/sleep
import time
#using math library for ceil and floor to intiger
import math 
#using LiDAR library to configure speed of LiDAR
import rplidar
#using RPLidar from LiDAR library to use data extraction APIs
from rplidar import RPLidar
#lidar usb port connection identification of position
lidar = RPLidar('/dev/ttyUSB0')

#the list that contains the extracted lists
list =[]

#creating an SPI object from the library
spi = spidev.SpiDev()
#choosing From SPI1 the first slave select as the connection
spi.open(0, 0)
#configuring speed of SPI that matches the AVR microcontroller (976 kHz)
spi.max_speed_hz = 976000 

#a counter which measures the number of lists extracted
list_count = 0
#list of qualities for each range of reading
quality = [0]*18
#list of distances for each range of reading
distance = [0]*18
#list of number of data taken by this range for each range of reading 
counter = [0]*18
#average quality of this range without ceil
Average_Q = [0]*18 
#average quality of this range after the ceil
Average_Q_ceil = [0]*18
#average distances of this range without ceil
Average_D = [0]*18
#average distances of this range after the ceil
Average_D_ceil = [0]*18
#configuring LiDAR speed
lidar.motor_speed = 612

#exception handling for safe exit when interrupt by RPI
try:
	#a loop for the application to keep on operating
	while True:
		#intially intialize the list with empty values
		list = []
		#intialize the other lists for the begining of data extraction
		quality = [0]*18
		distance = [0]*18
		counter = [0]*18
		Average_Q = [0]*18 
		Average_Q_ceil = [0]*18
		Average_D = [0]*18
		Average_D_ceil = [0]*18
		#reconnecting the LiDAR after the disconnecting
		lidar.connect()
		#for loop to fetch data from LiDAR by variable 
		for data_index, data_list in  enumerate(lidar.iter_scans(max_buf_meas=5320,min_len=8)):
			#counting number of lists by incrementing for each list
			list_count = list_count + 1
			#adding the new list
			list.append(data_list)
			#exit condition for list additions
			if(list_count == 5):
				#stopping the light emittion
				lidar.stop()
				#stopping the LiDAR motor
				lidar.stop_motor()
				#starting the counter by zero for new looping
				list_count = 0
				#disconnecting the LiDAR
				lidar.disconnect()
				#breaking the looping on data from LiDAR
				break
		#looping on each list of the extracted lists
		for m_list in list:
			#looping on each tuple inside this list
			for data_tuple in m_list:
				#printing the tuple on terminal for debugging
				print(data_tuple)
				#making sure to only use data with light quality above 9 (medium quality or above)
				if( data_tuple[0] > 9 ):
					#looping on each angle of the filtered range to extract data of each range for later averageing
					for range_specifier in range(20,361,20):
						#getting the index of this angle by the means of equation
						range_index = int((range_specifier/20)-1)
						#finding which range it belongs to
						if  (data_tuple[1] >=range_specifier-20 and data_tuple[1] <=range_specifier) :
							#adding the distance to the total distances of this range
							distance[range_index] = distance[range_index] + int(math.ceil(data_tuple[2]))
							#adding the quality to the total qualities of this range
							quality[range_index] = quality[range_index] + int(math.ceil(data_tuple[0]))
							#incrementing the list of number of data in this range
							counter[range_index] = counter[range_index] + 1
		#looping if a range didn,t have data to but a value that can be identified by the target when recieving it
		for data_index in range(0,18,1):
			#if no value was given to this range
			if (counter[data_index] == 0):
				#put 1 inside this data to avoid dividing by zero
				counter[data_index] = 1
				#put 255 for the quality for AVR to identify
				quality[data_index] = 255
				#put a distance of range that below the acceptable range of movement
				distance[data_index] = 10
		#looping on the ranges for SPI sending
		for range_specifier in range(10,361,20):
			#getting the index of this angle by the means of equation
			angle_index = int(((range_specifier-10)/20))
			#calculating the average quality
			Average_Q[angle_index] = quality[angle_index] / counter[angle_index]
			#ceil its value for avoid sending decimals 
			Average_Q_ceil[angle_index] = math.ceil(Average_Q[angle_index])
			#sending the average ceiled quality by SPI
			spi.xfer([Average_Q_ceil[angle_index]])
			#this time is set tomake sure that data was sent and that SPI is ready to send other data
			time.sleep(0.01)
			#sending angle identifier of the range by firstly sending its hundered's term
			spi.xfer([(math.floor(((range_specifier)/100)))])
			#this time is set tomake sure that data was sent and that SPI is ready to send other data
			time.sleep(0.01)
			#then sending the rest of the angle
			spi.xfer([((range_specifier%100))])
			#this time is set tomake sure that data was sent and that SPI is ready to send other data
			time.sleep(0.01)
			#calculating the average distance
			Average_D[angle_index] = distance[angle_index] / counter[angle_index]
			#ceil its value by cm for avoiding sending decimals
			Average_D_ceil[angle_index] = math.ceil(Average_D[angle_index]/10)
			#checking if the data exceeds the SPI frame range as distances above 256 cm is not benificial to our application
			if Average_D_ceil[angle_index] > 255 :
				#mentaining the distances above this range to a constant value of 256 cm
				Average_D_ceil[angle_index] = 255
			#transfering the ceiled calculated average of the distance
			spi.xfer([Average_D_ceil[angle_index]])
			#this time is set tomake sure that data was sent and that SPI is ready to send other data
			time.sleep(0.01)
#exception handling
except KeyboardInterrupt:
	#stopping the LiDAR light emission
	lidar.stop()
	#stopping the LiDAR motor
	lidar.stop_motor()
	#disconnecting the LiDAR
	lidar.disconnect()
	#transfering error frame
	spi.xfer([99,99,99,99])