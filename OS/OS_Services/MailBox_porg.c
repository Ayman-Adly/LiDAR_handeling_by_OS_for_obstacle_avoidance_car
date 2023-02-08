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
		M->Data = (u8 **)malloc(2+size*2);
		if(M->Data==NULL)
		{
			free(M->Data);
			successfull_OR_NOT = Not_successfull;
		}
		else
		{
		M->Mailbox_DataSize=size;
		M->ptr = (u8 *)(M->Data+2);
		}
	return successfull_OR_NOT;
}


/***********************************************************************************************************************************
*Description: this function is used to Send Massege to mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 			
*@pram		: DataType 	--> void  pointer locating data Address	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege - if data max size is 8 bytes more will overflow
*
*@return		: SMS enum value either holding (Fail) could not Send OR  (Success) Send Done 
************************************************************************************************************************************/
SMS OS_enuMailbox_Send(Mailbox *M,void *copy_of_data_type,Size data)
{
		u8 ReturnState;  // 0(Fail)   or   1(Success)	
		u8 *ptr =  (u8*)copy_of_data_type;
		if(M->Mailbox_Send_flag == full) 
		{
			ReturnState = Fail;
		}
		else if(M->Mailbox_Send_flag == empty)
		{
			for(u8 i=0 ; i < 2 ; i++ )
			{
				M->Data[i] = (M->ptr + M->Mailbox_DataSize * i);
			}
			if(M->Mailbox_Receive_flag==empty)
			{
				M->Mailbox_Send_flag=full;
				if(data > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow 
					
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						M->Data[empty][i] = *ptr++;
					}
				
				}
				else
				{
					for(u8 i=0 ; i < data ; i++ )
					{
						M->Data[empty][i] = *ptr++;
					}
				}
				M->Mailbox_Send_flag=empty;
				ReturnState =Success;
			}
			else if(M->Mailbox_Receive_flag==full)
			{
				if(M->Mailbox_SBF==full)
				{
				
					M->Mailbox_Send_flag=full;
					if(data > M->Mailbox_DataSize)
					{
						//warning Massege	that i'll only save on Mailbox Size and data will overflow
						for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
						{
							M->Data[empty][i] = *ptr++;
						}			
					}
					else
					{
						for(u8 i=0 ; i < data ; i++ )
						{
							M->Data[empty][i] = *ptr++;
						}
					}
					M->Mailbox_SBF=full;
					M->Mailbox_Send_flag=empty;
					ReturnState = Success;
				}
				else
				{
					M->Mailbox_Send_flag=full;
					if(data > M->Mailbox_DataSize)
					{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
						for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
						{
							M->Data[full][i] = *ptr++;
						}				
					}
					else
					{
						for(u8 i=0 ; i < data ; i++ )
						{
							M->Data[full][i] = *ptr++;
						}
					}
					M->Mailbox_SBF=full;
					M->Mailbox_Send_flag=empty;
					ReturnState = Success;
				}
			}
		}
	return ReturnState;
}

/***********************************************************************************************************************************
*Description: this function is used to Receive Massege from mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created
*@pram		: DataType 	--> void pointer locating Address to Put Data into	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege - note data max size is 8 bytes more will overflow
*
*@return	: void 
************************************************************************************************************************************/
void OS_VidMailbox_Receive(Mailbox *M,void *copy_of_data_type,Size data)
{
	u8 *ptr = (u8*) copy_of_data_type;
		if(M->Mailbox_Send_flag == empty) 
		{
			for(u8 i=0 ; i < 2 ; i++ )
			{
				M->Data[i] = (M->ptr + M->Mailbox_DataSize * i);
			}	
			if(M->Mailbox_SBF==full)
			{
				M->Mailbox_Receive_flag=full;
				
				if(data > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[full][i];
					}		
				}
				else
				{
					for(u8 i=0 ; i < data ; i++ )
					{
						*ptr++= M->Data[full][i];
					}
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
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}
				}
				else
				{
					for(u8 i=0 ; i < data ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}
				}
				M->Mailbox_Receive_flag=empty; // to test functionality
			}
		}
		
}
