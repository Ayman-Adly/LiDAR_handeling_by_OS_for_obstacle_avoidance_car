/**
 * @file HMD_L298N_Config.h.
 * @author Hisham Montaser. 
 * @brief This is the HMD_L298N_Config.h for file configraution.
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file gives the ability for the user to feel some sort of felxibilty with the chocies the developer made .
 */
/**************************************************************************************************************/
/*                       HeaderGuard : Prevent Multiple calls of Config.h header file                         */
/**************************************************************************************************************/

#ifndef HMD_L298N_CONFIG_H_
#define HMD_L298N_CONFIG_H_

/* Select The Pins On AVR That Input_1, Input_2, Input_3, Input_4 Will Be Connected On. */
/*Options : 1)PIN0
 		    2)PIN1
 		 	3)PIN2
  			4)PIN3
  			5)PIN4
  			6)PIN5
  			7)PIN6
  			8)PIN7 */

#define Input_1MA  PIN0
#define Input_2MA  PIN1
#define Input_3MB  PIN2
#define Input_4MB  PIN7


#endif /* HMD_L298N_CONFIG_H_ */
