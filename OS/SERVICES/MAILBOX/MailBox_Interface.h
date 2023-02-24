
/*********************************************************************************************
 * @file MailBOX_Interface.h
 * @author Ahmed Emad Ahmed 
 * @brief This is the MailBOX_Interface.h file for defining function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 *
 *********************************************************************************************/
 
/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Interface.h  		                      */
/**************************************************************************************************************/
#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H


typedef struct 
{
	u8 		Mailbox_Receive_flag;  //Receive flag to Know if you are Receiving Or Not Receiving
	u8 		Mailbox_Send_flag;	   //Send flag to Know if you are Sending Or Not Sending 
	u8 		Mailbox_SBF;		   //Second Buffer Flag to Know if you Sended On Second Buffer Or didn't 
	u8		Mailbox_DataSize;      //Data Size To Know Data Size Of Created Memory by User 
	u8		*Data[2];			   //pointer to Array of size 2 to Hold Addresses of Allocated Space 
}Mailbox;

 
/************************************************************************************************************************************/
/************************************************ Public Functions ******************************************************************/
/************************************************************************************************************************************/

/***********************************************************************************************************************************
*@brief		 this function is used to create a mail-box data size in run-time.
*This is Detailed Description: This function takes Pointer to Mailbox created and size of bytes to allocate in created Mailbox,
*if size allocated successfully will return (SUCCESS) ,if size failed to be allocated will return (FAIL) .
*
*@param		 *M								--> pointer to Mailbox  	
*@param		 SizeOfMailboxMassegeBuffer 	--> Size of bytes needed to hold data 
*
*@return	 State_t  	
************************************************************************************************************************************/		
State_t OS_sttMailboxCreate(Mailbox *M,u16 SizeOfMailboxMassegeBuffer);


/**************************************************************************************************************************************************
*@brief		 this function is used to Send Massege to mail-box.
*This is Detailed Description : This function takes Pointer to Mailbox created and pointer to Data Sended and Size of Data Sended in bytes.
*
*@param		 *M						--> Pointer to Mailbox created 			
*@param		 PointerToDataSended 	--> void pointer to pointer locating data Address 	
*@param		 SizeOfDataSended 		--> Size of bytes needed to hold data  OR Size of Massege 
*@attention	 if bytes Sended Less than data Size Sended will Result in Garbage Value. 
*
*@return	 State_t 
************************************************************************************************************************************/			
State_t OS_sttMailboxSend( Mailbox *M, void *PointerToDataSended ,u16 SizeOfData);


/*************************************************************************************************************************************************
*@brief		 this function is used to Receive Massege from mail-box.
*This is Detailed Description : This function takes Pointer to Mailbox created and Pointer To Receive Location and Size of Data Sended in bytes.
*
*@param		 *M							--> Pointer to Mailbox created
*@param		 PointerToReceiveLocation 	--> void pointer to pointer locating Address to Put Data into	
*@param		 SizeOfDataRecived			--> Size of bytes needed to hold data  OR Size of Massege Received 
*@attention	 note data max size is Max Created bytes in Create any more will be overlooked.
*
*@return	 void 
************************************************************************************************************************************/	
void OS_vidMailboxReceive( Mailbox *M,void *PointerToDataRecived,u16 SizeOfDataRecived);

#endif
