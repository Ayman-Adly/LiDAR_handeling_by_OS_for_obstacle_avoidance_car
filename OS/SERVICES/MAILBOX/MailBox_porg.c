/*********************************************************************************************
 * @file MailBOX_Prog.c
 * @author Ahmed Emad Ahmed 
 * @brief This is the MailBOX_Prog.c file for defining function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 *
 *********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************************************************************/
/*                                             	 Standard types LIB                                           					 */
/********************************************************************************************************************************/
#include"../../../LIB/STD_Types.h"


/********************************************************************************************************************************/
/*                                   				Own Header                                                                 */
/******************************************************************************************************************************/
#include"MailBox_Priv.h"
#include"MailBox_Interface.h"

/************************************************************************************************************************************/
/************************************************ Public Functions ******************************************************************/
/************************************************************************************************************************************/


/***********************************************************************************************************************************
*@brief		 this function is used to create a mail-box data size in run-time.
*This is Detailed Description: This function takes Pointer to Mailbox created and size of bytes to allocate in created Mailbox,
*if size allocated successfully will return (SUCCESS) ,if size failed to be allocated will return (FAIL) .
*
*@param		 *M		--> pointer to Mailbox  	
*@param		 size 	--> Size of bytes needed to hold data 
*
*@return	 State_t  	
************************************************************************************************************************************/		
State_t OS_sttMailboxCreate(Mailbox *M,u16 size)
{
		// initial State Success upon Creation
		State_t State = STATE_SUCCESS;
		//initial value of Receive flag is not Receiving
		M->Mailbox_Receive_flag=Not_Receiving;
		//initial value of Send flag is not Sending
		M->Mailbox_Send_flag=Not_Sending;
		//initial value of Second Buffer is not Used
		M->Mailbox_SBF=Not_Used;
		
		//Trying To Allocate 2 Places For Data for Double Buffer Technique
		
		//Trying to Allocate The Size User Defined and putting Address in Data[empty] location 
		M->Data[empty] =(u8 *)malloc(size);
		//Trying to Allocate The Size User Defined and putting Address in Data[full] location 
		M->Data[full] =(u8 *)malloc(size);
		
		//checking if either One of Located Addresses is Equal to NULL 
		if(M->Data[empty]==NULL||M->Data[full]==NULL)
		{
			//freeing Located Location of Data[empty]
			free(M->Data[empty]);
			//freeing Located Location of Data[full]
			free(M->Data[full]);
			//Changing State to Fail
			State = STATE_FAIL;
		}
		else
		{
			// after Successfull Allocation Adding User Defined Size as main size of Mailbox Massege
			M->Mailbox_DataSize=size;
		}
	//return either (SUCCESS) OR (FAIL)
	return State;
}


/**************************************************************************************************************************************************
*@brief		 this function is used to Send Massege to mail-box.
*This is Detailed Description : This function takes Pointer to Mailbox created and pointer to Data Sended and Size of Data Sended in bytes.
*
*@param		 *M						--> Pointer to Mailbox created 			
*@param		 PointerToDataSended 	--> void pointer to pointer locating data Address 	
*@param		 SizeOfDataSended 		--> Size of bytes needed to hold data  OR Size of Massege 
*@attention  if bytes Sended Less than data Size Sended will Result in Garbage Value. 
*
*@return	 State_t 
************************************************************************************************************************************/	
State_t OS_sttMailboxSend(Mailbox *M,void *PointerToDataSended,u16 SizeOfDataSended)
{
		//initial ReturnState FAIL upon Creation
		State_t ReturnState=STATE_FAIL;  // 255(FAIL)   or   1(SUCCESS)
		// initialize  u8 counter for Loops
		u8 counter=0;
		if(PointerToDataSended==NULL)
		{
			//ReturnState equals FAIL
			ReturnState = STATE_FAIL;
		}
		else
		{
			//casting void pointer of Data Sended to byte Size & making byte size pointer to move on data with it
			u8 *ptr =  (u8*)PointerToDataSended;
			//checking if Mailbox is Interrupted During Sending 
			if(M->Mailbox_Send_flag == Sending) 
			{
				// ReturnState equals FAIL
				ReturnState = STATE_FAIL;
			}
			//Checking if Mailbox have no other Senders 
			else if(M->Mailbox_Send_flag == Not_Sending)
			{
				//making Send Flag equal Sending 
				M->Mailbox_Send_flag=Sending;
				//Checking on Receive Flag to Avoid Corrupting Data if Not Receiving
				if(M->Mailbox_Receive_flag==Not_Receiving)
				{
					//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
					if(SizeOfDataSended > M->Mailbox_DataSize)
					{
						//warning Massege	that i'll only save on Mailbox Size and data will overflow 
						
						//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
						for( counter ; counter < M->Mailbox_DataSize ; counter++ )
						{
							M->Data[empty][counter] = *ptr++;
						}
					
					}
					else
					{
						//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte
						for( counter ; counter < SizeOfDataSended ; counter++ )
						{
							M->Data[empty][counter] = *ptr++;
						}
					}
				}
				//Checking on Receive Flag to Avoid Corrupting Data if Receiving
				else if(M->Mailbox_Receive_flag==Receiving)
				{
					//Checking if I'm Using Second Buffer by Checking Second Buffer Flag 
					if(M->Mailbox_SBF==Used)
					{
						//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
						if(SizeOfDataSended > M->Mailbox_DataSize)
						{
							//warning Massege	that i'll only save on Mailbox Size and data will overflow
							
							//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte
							for( counter ; counter < M->Mailbox_DataSize ; counter++ )
							{
								M->Data[empty][counter] = *ptr++;
							}			
						}
						else
						{
							//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte
							for( counter ; counter < SizeOfDataSended ; counter++ )
							{
								M->Data[empty][counter] = *ptr++;
							}
						}
					}
					else
					{
						//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
						if(SizeOfDataSended > M->Mailbox_DataSize)
						{
						//warning Massege	that i'll only save on Mailbox Size and data will overflow
						
							//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte
							for( counter ; counter < M->Mailbox_DataSize ; counter++ )
							{
								M->Data[full][counter] = *ptr++;
							}				
						}
						else
						{	
							
							//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte
							for( counter ; counter < SizeOfDataSended ; counter++ )
							{
								M->Data[full][counter] = *ptr++;
							}
						}
						//Setting Second Buffer Flag as Used to Receive to be Cleared by Receive when Read 
						M->Mailbox_SBF=Used;
					}
				}
					//Setting Send Flag to Not Sending as i Finshed Sending
					M->Mailbox_Send_flag=Not_Sending;
					//retun Success to User 
					ReturnState =STATE_SUCCESS;
			}
		}
	//return ReturnState either Success or Fail
	return ReturnState;
}

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
void OS_vidMailboxReceive(Mailbox *M,void *PointerToReceiveLocation,u16 SizeOfDataRecived)
{
		//casting void pointer of Receive Location to byte Size & making byte size pointer to move on data with it
		u8 *ptr = (u8*) PointerToReceiveLocation;
		// initialize  u8 counter for Loops
		u8 counter=0;
		//Setting Receive Flag as Receiving as i'm about to put Data in Located pointer
		M->Mailbox_Receive_flag=Receiving;
		//Checking if i'm not Sending Data by Checking on Send Flag
		if(M->Mailbox_Send_flag == Not_Sending) 
		{
			//Cheking if Second Buffer Was Written On
			if(M->Mailbox_SBF==Used)
			{
				//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < M->Mailbox_DataSize ; counter++ )
					{
						*ptr++= M->Data[full][counter];
					}		
				}
				else
				{
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < SizeOfDataRecived ; counter++ )
					{
						*ptr++= M->Data[full][counter];
					}
				}
				//Setting Second Buffer Flag as Not Used
				M->Mailbox_SBF=Not_Used;
			}
			else
			{
				//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
				
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < M->Mailbox_DataSize ; counter++ )
					{
						*ptr++= M->Data[empty][counter];
					}
				}
				else
				{
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < SizeOfDataRecived ; counter++ )
					{
						*ptr++= M->Data[empty][counter];
					}
				} 
			}
		}
		else if(M->Mailbox_Send_flag == Sending)
		{
			if(M->Mailbox_SBF==Used)
			{
				//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < M->Mailbox_DataSize ; counter++ )
					{
						*ptr++= M->Data[empty][counter];
					}		
				}
				else
				{
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < SizeOfDataRecived ; counter++ )
					{
						*ptr++= M->Data[empty][counter];
					}
				}
			}
			else
			{
				//Checking on Size of Data Sended by User to be Less or Equal Size of Created Mailbox Data Size
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < M->Mailbox_DataSize ; counter++ )
					{
						*ptr++= M->Data[full][counter];
					}		
				}
				else
				{
					//for loop to Take Data from Data Sended & Receive it in Mailbox byte by byte 
					for( counter ; counter < SizeOfDataRecived ; counter++ )
					{
						*ptr++= M->Data[full][counter];
					}
				}
			}
		}
		//Setting Receive flag Not Receiving as function ended Reading Values
		M->Mailbox_Receive_flag=Not_Receiving;
}
