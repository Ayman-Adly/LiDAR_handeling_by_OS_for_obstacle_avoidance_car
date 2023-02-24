/*********************************************************************************************
 * @file MailBOX_Priv.h
 * @author Ahmed Emad Ahmed 
 * @brief This is the MailBOX_Private.h file for defining Special enum Used in MailBOX_Prog . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 *********************************************************************************************/
 
/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Private.h  			                      */
/**************************************************************************************************************/

#ifndef SERVICES_PRIV_H
#define SERVICES_PRIV_H

//@brief This enum is for State of Massege 
typedef enum{
	empty=0, //empty
	full=1	 //full
}MSTATE; //state of massege

//@brief This enum is for Receive flag
typedef enum{
	Not_Receiving=0,
	Receiving=1
}RECEIVE;//RECEIVE

//@brief This enum is for Send flag
typedef enum{
	Not_Sending=0,
	Sending=1
}SEND;//SEND

//@brief This enum is for Second Buffer flag
typedef enum{
	Not_Used=0,
	Used=1
}SECOND_BUFFER;//SECOND BUFFER


#endif/* MailBox_PRIV_H_ */