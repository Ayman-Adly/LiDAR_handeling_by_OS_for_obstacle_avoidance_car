/***************************************************************************************************************
*@author	:       Hisham_Montaser (and) Ayman El-Tanboly (and) Moamen Ehab (and) Ehap Ashraf (and) Ahmed Emad
*@date		:       22 - 1 - 2023                                                                           
*@version	:       v0.0.0                                                                                  
*@brief 	:       IDevelop Some Application                                                               
****************************************************************************************************************/
/****************************************************************************************************************/
/*                                Standard Types LIB                                                            */
/****************************************************************************************************************/
#include "../LIB/STD_Types.h"


/****************************************************************************************************************/
/*                                       OS Stack                                                               */
/****************************************************************************************************************/
#include"../OS/SCHEDULER/OS_Interface.h"
#include"../OS/SERVICES/MAILBOX/MailBox_Interface.h"

/****************************************************************************************************************/
/*                                       MCAL                                                                   */
/****************************************************************************************************************/
#include"../MCAL/DIO/DIO_INTERFACE.h"
#include"../MCAL/TIMER/Timer0_Interface.h"
#include"../MCAL/SPI/MSPI_Interface.h"

/****************************************************************************************************************/
/*                                       HAL                                                                    */
/****************************************************************************************************************/
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/L298N/HMD_L298N_Interface.h"


//mailbox creation
Mailbox Distance_Matrix;



/**************************************************************************************************************
 * @brief car control task
 * 
 **************************************************************************************************************/
void Car_Control (void);

/**************************************************************************************************************
 * @brief Data display on LCD
 * 
 **************************************************************************************************************/
void Display_Data (void);

/**************************************************************************************************************
 * @brief data receive by SPI task
 * 
 **************************************************************************************************************/
void Recieve_Data (void);

/**************************************************************************************************************
 * @brief main function
 * 
 * @return int --> zero 
 **************************************************************************************************************/
int main(){


	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	//output LED Slave connection
	DIO_voidSetPinDirection(PORTA , PIN1 , OUTPUT);
	//SS
	DIO_voidSetPinDirection(PORTB , PIN4 , INPUT);
	DIO_voidSetPinDirection(PORTB , PIN4 , HIGH);
	//clock
	DIO_voidSetPinDirection(PORTB , PIN7 , INPUT);
	//MOSI
	DIO_voidSetPinDirection(PORTB , PIN5 , INPUT);
	//MISO
	DIO_voidSetPinDirection(PORTB , PIN6 , OUTPUT);
	//SPI init
	MSPI_voidInit();
	//LCD init
	DIO_voidSetPinDirection(PORTD,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN4,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN7,OUTPUT);

	DIO_voidSetPinDirection(PORTC,PIN4,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN5,OUTPUT);

	LCD_vidInit();

	/* Set Used Pin Directions */
	DIO_voidSetPinDirection(PORTC,Input_1MA,OUTPUT);
	DIO_voidSetPinDirection(PORTC,Input_2MA,OUTPUT);
	DIO_voidSetPinDirection(PORTC,Input_3MB,OUTPUT);
	DIO_voidSetPinDirection(PORTC,Input_4MB,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
	/* Initialize timer */
	MTimer0_voidInit();
	MTimer0_voidSetCompareMatchValue(155);
	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	//creating mailbox
	OS_sttMailboxCreate(&Distance_Matrix,8);
	//creating data SPI receiving task
	OS_sttCreateTask(0,300,&Recieve_Data,0);
	//creating task to display data on LCD
	OS_sttCreateTask(2,1000,&Display_Data,0);
	//creating task to control car movements
	OS_sttCreateTask(1,300,&Car_Control,0);
	//intializing the OS
	OS_vidStart();
	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	/****************************************************************************************************************************/
	
	//application looping
	while(1)
	{

	}

	return 0;
}

/**************************************************************************************************************
 * @brief car control task
 * 
 **************************************************************************************************************/
void Car_Control (void)
{
	// time lock counts
	u8 u8time;
	//creating the receive of mailbox
	u8 LCD_MailBox_Receive[8];
	//receiving the mailbox on our variable
	OS_vidMailboxReceive(&Distance_Matrix,&LCD_MailBox_Receive,8);

	//checking that front distance became lesser than 30 cm
	if (LCD_MailBox_Receive[0] < 30)
	{
		//checking that the front left and the front right if they are lesser than 30 cm
		if( (LCD_MailBox_Receive[3]  < 30) && (LCD_MailBox_Receive[2] < 30)  )
		{
			//checking that the left and the right if they are lesser than 30 cm
			if ( (LCD_MailBox_Receive[6] < 30) && (LCD_MailBox_Receive[7] < 30 ) )
			{
				//checking that the back left and the back right if they are lesser than 30 cm
				if ( (LCD_MailBox_Receive[5] < 30)&& (LCD_MailBox_Receive[4] < 30) )
				{
					//checking if the back distance became lesser than 30 cm
					if ( LCD_MailBox_Receive[1] < 30 )
					{
						/*Car Stops*/
						HMD_L298N_MotorStop(PORTC);
					}
					//turning to face the back and move
					else
					{
						//turning right to face backward
						for(u8time=200;u8time>0;u8time--)
						{
							HMD_L298N_DirectionRight(PORTC);
						}
					}
				}
				//front back left and back right doesn't face obstacles
				else
				{
					//lesser obstacles in the back right direction than the back left direction
					if(LCD_MailBox_Receive[5]  > LCD_MailBox_Receive[4] )
					{
						//turning right to face back right
						for(u8time=150;u8time>0;u8time--)
						{
							HMD_L298N_DirectionRight(PORTC);
						}
					}
					//lesser obstacles in the back left direction than the back right direction
					else
					{
						//turning left to face back left
						for(u8time=150;u8time>0;u8time--)
						{
							HMD_L298N_DirectionLeft(PORTC);
						}
					}
				}
			}
			//left and right doesn't face obstacles
			else
			{
				//lesser obstacles in the right direction than the left direction
				if(LCD_MailBox_Receive[6]  > LCD_MailBox_Receive[7])
				{
					//turning right to face right
					for(u8time=100;u8time>0;u8time--)
					{
						HMD_L298N_DirectionRight(PORTC);
					}
				}
				//lesser obstacles in the left direction than the right direction
				else
				{
					//turning left to face left
					for(u8time=100;u8time>0;u8time--)
					{
						HMD_L298N_DirectionLeft(PORTC);
					}
				}
			}
		}
		//front left front and right front doesn't face obstacles
		else
		{
			//lesser obstacles in the right front direction than the left front direction
			if(LCD_MailBox_Receive[3]  > LCD_MailBox_Receive[2] )
			{
				//turning right to face front right
				for(u8time=50;u8time>0;u8time--)
				{
					HMD_L298N_DirectionRight(PORTC);
				}
			}
			//lesser obstacles in the left front direction than the right front direction
			else
			{
				//turning left to face front left
				for(u8time=50;u8time>0;u8time--)
				{
					HMD_L298N_DirectionLeft(PORTC);
				}
			}

		}
	}
	//there is no obstacle in the front motion
	else
	{
		/* Car is Moving forward till it can't enter this start anymore */
		HMD_L298N_DirectionForward(PORTC);
	}


}

/**************************************************************************************************************
 * @brief Data display on LCD
 * 
 **************************************************************************************************************/
void Display_Data (void)
{
	//creating the array to receive data
	u8 LCD_MailBox_Receive[8];
	//receiving the data in our array
	OS_vidMailboxReceive(&Distance_Matrix,&LCD_MailBox_Receive,8);
	//clear the LCD
	LCD_vidSendCommand(LCD_CLR);
	//return to the beginning of the LCD
	LCD_vidSendCommand(LCD_HOME);
	//write forward symbol
	LCD_vidWriteStr("F: ");
	//write forward value
	LCD_vidSendNum(LCD_MailBox_Receive[0]);
	//write backward symbol
	LCD_vidWriteStr("  B: ");
	//write backward valu
	LCD_vidSendNum(LCD_MailBox_Receive[1]);
	//go to the second line
	LCD_vidGetPosition(1,0);
	//write right symbol
	LCD_vidWriteStr("R: ");
	//write right value
	LCD_vidSendNum(LCD_MailBox_Receive[6]);
	//write left symbol
	LCD_vidWriteStr("    L: ");
	//write left value
	LCD_vidSendNum(LCD_MailBox_Receive[7] );

}

/**************************************************************************************************************
 * @brief data receive by SPI task
 * 
 **************************************************************************************************************/
void Recieve_Data (void)
{
	//the amilbox of readings:
	u8 Data_MailBox[8];
	//Data re fetching
	//front distance
	u8 u8front      = 0;
	//back distance
	u8 u8back       = 0;
	//front left distance
	u8 u8leftfront  = 0;
	//front right distance
	u8 u8rightfront = 0;
	//back left distance
	u8 u8leftback   = 0;
	//back right distance
	u8 u8rightback  = 0;
	//right distance
	u8 u8right      = 0;
	//left distance
	u8 u8left       = 0;
	//buffer for angles data
	u8 u8righta     = 0;
	u8 u8rightb     = 0;
	u8 u8lefta      = 0;
	u8 u8leftb      = 0;
	//general data receiver
	u8 Data         = 15;
	//loop until you check that all data have been received
	while(u8back==0 || u8front==0 || u8lefta==0 || u8leftb==0 || u8righta==0 || u8rightb==0 || u8leftfront  == 0 || u8rightfront == 0 || u8leftback  == 0 || u8rightback == 0)
	{
		//pulling on data until a number matches the angle format to receive the distance of this angle
		MSPI_u8SlaveDataPulling(&Data,0);
		//check for angles below 100 degree
		if(Data==0)
		{
			//pulling on the tens term
			MSPI_u8SlaveDataPulling(&Data,0);
			//for angle 10 degree
			if(Data==10)
			{
				//pulling for the distance of the first angle from the right direction
				MSPI_u8SlaveDataPulling(&u8righta,0);
			}
			//for angle 50 degree
			else if(Data==50)
			{
				//pulling for the distance of the angle of the right front direction
				MSPI_u8SlaveDataPulling(&u8rightfront,0);
			}
			//for angle 90 degree
			else if(Data==90)
			{
				//pulling for the distance of the angle of the front direction
				MSPI_u8SlaveDataPulling(&u8front,0);
			}
		}
		//check for angles between 100 and 200 degrees
		else if(Data==1)
		{
			//pulling on the tens term
			MSPI_u8SlaveDataPulling(&Data,0);
			//for angle 130 degree
			if(Data==30)
			{
				//pulling for the distance of the angle of the left front direction
				MSPI_u8SlaveDataPulling(&u8leftfront,0);
			}
			//for angle 170 degree
			else if(Data==70)
			{
				//pulling for the distance of the first angle from the left direction
				MSPI_u8SlaveDataPulling(&u8lefta,0);
			}
			//for angle 190 degree
			else if(Data==90)
			{
				//pulling for the distance of the second angle from the left direction
				MSPI_u8SlaveDataPulling(&u8leftb,0);
			}
		}
		//check for angles between 200 and 300 degrees
		else if(Data==2)
		{
			//pulling on the tens term
			MSPI_u8SlaveDataPulling(&Data,0);
			//for angle 230 degree
			if(Data==30)
			{
				//pulling for the distance of the angle of the left back direction
				MSPI_u8SlaveDataPulling(&u8leftback,0);
			}
			//for angle 270 degree
			else if(Data==70)
			{
				//pulling for the distance of the angle of the backdirection
				MSPI_u8SlaveDataPulling(&u8back,0);
			}
		}
		//check for angles between 300 and 360 degrees
		else if(Data==3)
		{
			//pulling on the tens term
			MSPI_u8SlaveDataPulling(&Data,0);
			//for angle 310 degree
			if(Data==10)
			{
				//pulling for the distance of the angle of the right back direction
				MSPI_u8SlaveDataPulling(&u8rightback,0);
			}
			//for angle 350 degree
			else if(Data==50)
			{
				//pulling for the distance of the second angle from the right direction
				MSPI_u8SlaveDataPulling(&u8rightb,0);
			}
		}
		//you have recieved error frame
		else if (Data==99)
		{
			//multiple checking if it is really an error frame
			MSPI_u8SlaveDataPulling(&Data,0);
			if(Data==99)
			{
				MSPI_u8SlaveDataPulling(&Data,0);
				if(Data==99)
				{
					MSPI_u8SlaveDataPulling(&Data,0);
					if(Data==99)
					{
						/*change while integration*/
						//clear the LCD
						LCD_vidSendCommand(LCD_CLR);
						//return to the beginning of the LCD
						LCD_vidSendCommand(LCD_HOME);
						//diplay you recieved error
						LCD_vidWriteStr("Data Error");
						//loop for system failure
						while(1);
					}
				}
			}
		}
	}
	//calculating the average for the right angle
	u8right = (u8righta+u8rightb)/2;
	//calculating the average for the left angle
	u8left = (u8lefta+u8leftb)/2;
	//the inserting the data in the mailbox:
	//front distance
	Data_MailBox[0]  = u8front;
	//back distance
	Data_MailBox[1] = u8back;
	//front left distance
	Data_MailBox[2] =  u8leftfront;
	//front right distance
	Data_MailBox[3] = u8rightfront;
	//back left distance
	Data_MailBox[4] =  u8leftback;
	//back right distance
	Data_MailBox[5] =  u8rightback;
	//right distance
	Data_MailBox[6] =  u8right;
	//left distance
	Data_MailBox[7] =  u8left;
	//send mailbox
	OS_sttMailboxSend(&Distance_Matrix,&Data_MailBox,8);
}
