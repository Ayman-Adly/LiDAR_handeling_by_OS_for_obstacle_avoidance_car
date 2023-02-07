#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"

#include"MailBox_Priv.h"
#include"MailBox_Interface.h"


/***********************************************************************************************************************************
*Description: this function is used to create a mail-box data size in run-time 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 	
*@pram		: Size 		--> Size of bytes needed to hold data 
*
*@return		: MBS enum value either holding (successfull) location Reserved OR  ERROR could not Reserve location (Not_successfull)	
************************************************************************************************************************************/
MBS OS_enuMailbox_Create(Mailbox *M,Size size)
{
		u8 successfull_OR_NOT = successfull;
		M->Mailbox_Receive_flag=empty;
		M->Mailbox_Send_flag=empty;
		M->Mailbox_SBF=empty;
		M->Data[empty]=NULL;
		M->Data[full]=NULL;
		M->Data[empty]=malloc(size);
		M->Data[full]=malloc(size);
		if(M->Data[empty]==NULL||M->Data[full]==NULL)
		{
			free(M->Data[empty]);
			free(M->Data[full]);
			successfull_OR_NOT = Not_successfull;
		}
		else
		{
			 M->Mailbox_DataSize=size;
			if(size <= One_byte)
			{
				*(u8*)M->Data[empty]=0;
			}
			else if(size <= two_bytes)
			{
				*(u16*)M->Data[empty]=0;
			}
			else if(size > two_bytes&&size <= Four_bytes)
			{
				*(u32*)M->Data[empty]=0;
			}
			else 
			{
				*(f64*)M->Data[empty]=0;
			}
		}
	return successfull_OR_NOT;
}


/***********************************************************************************************************************************
*Description: this function is used to Send Massege to mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 			
*@pram		: DataType 	--> void pointer to pointer locating data Address	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege - if data max size is 8 bytes more will overflow
*
*@return		: SMS enum value either holding (Fail) could not Send OR  (Success) Send Done 
************************************************************************************************************************************/
SMS OS_enuMailbox_Send(Mailbox *M,void**copy_of_data_type,Size data)
{
		u8 ReturnState;  // 0(Fail)   or   1(Success)
		if(M->Mailbox_Send_flag == full) 
		{
			ReturnState = Fail;
		}
		else if(M->Mailbox_Send_flag == empty)
		{

			if(M->Mailbox_Receive_flag==empty)
			{
				M->Mailbox_Send_flag=full;
				if(data > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
				}
				if(data <= One_byte)
				{
					*(u8*)M->Data[empty]=*(u8*)copy_of_data_type;
				}
				else if(data <= two_bytes)
				{
					*(u16*)M->Data[empty]=*(u16*)copy_of_data_type;
				}
				else if(data>two_bytes&&data<=Four_bytes)
				{
					*(u32*)M->Data[empty]=*(u32*)copy_of_data_type;
				}
				else 
				{
					*(f64*)M->Data[empty]=*(f64*)copy_of_data_type;
				}
				M->Mailbox_Send_flag=empty;
				ReturnState =Success;
			}
			else if(M->Mailbox_Receive_flag==full)
			{
				M->Mailbox_Send_flag=full;
				if(data > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
				}
				if(data <= One_byte)
				{
					*(u8*)M->Data[full]=*(u8*)copy_of_data_type;
				}
				else if(data <= two_bytes)
				{
					*(u16*)M->Data[full]=*(u16*)copy_of_data_type;
				}
				else if(data>two_bytes&&data<=Four_bytes)
				{
					*(u32*)M->Data[full]=*(u32*)copy_of_data_type;
				}
				else 
				{
					*(f64*)M->Data[full]=*(f64*)copy_of_data_type;
				}
				M->Mailbox_SBF=full;
				M->Mailbox_Send_flag=empty;
				ReturnState = Success;
			}
		}
	return ReturnState;
}

/***********************************************************************************************************************************
*Description: this function is used to Receive Massege from mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created
*@pram		: DataType 	--> void pointer to pointer locating Address to Put Data into	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege - note data max size is 8 bytes more will overflow
*
*@return	: void 
************************************************************************************************************************************/
void OS_VidMailbox_Receive(Mailbox *M,void**copy_of_data_type,Size data)
{
	
		if(M->Mailbox_Send_flag == empty) 
		{
			if(M->Mailbox_SBF==full)
			{
				M->Mailbox_Receive_flag=full;
				
				if(data > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
				}
				if(data <= One_byte)
				{
					*(u8*)copy_of_data_type=*(u8*)M->Data[full];
				}
				else if(data <= two_bytes)
				{
					*(u16*)copy_of_data_type=*(u16*)M->Data[full];
				}
				else if(data>two_bytes&&data<=Four_bytes)
				{
					*(u32*)copy_of_data_type=*(u32*)M->Data[full];
				}
				else 
				{
					*(f64*)copy_of_data_type=*(f64*)M->Data[full];
				}
				M->Mailbox_Receive_flag=empty;
				M->Mailbox_SBF=empty;
			}
			else
			{
				M->Mailbox_Receive_flag=full;
				if(data > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
				}
				if(data <= One_byte)
				{
					*(u8*)copy_of_data_type=*(u8*)M->Data[empty];
				}
				else if(data <= two_bytes)
				{
					*(u16*)copy_of_data_type=*(u16*)M->Data[empty];
				}
				else if(data>two_bytes&&data<=Four_bytes)
				{
					*(u32*)copy_of_data_type=*(u32*)M->Data[empty];
				}
				else 
				{
					*(f64*)copy_of_data_type=*(f64*)M->Data[empty];
				}
				M->Mailbox_Receive_flag=empty; // to test functionality
			}
		}
		
}
