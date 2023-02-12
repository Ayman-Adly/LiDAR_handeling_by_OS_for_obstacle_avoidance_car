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
*@return	: MBS enum value either holding (successfull)-->(1) location Reserved OR  ERROR could not Reserve location (Not_successfull)-->(0)	
************************************************************************************************************************************/	
MBS OS_enuMailbox_Create(Mailbox *M,Size size)
{
		u8 successfull_OR_NOT = successfull;
		M->Mailbox_Receive_flag=empty;
		M->Mailbox_Send_flag=empty;
		M->Mailbox_SBF=empty;
		M->Data[0] = (u8 *)malloc(size);
		M->Data[1] =(u8 *)malloc(size);
		if(M->Data[0]==NULL||M->Data[1]==NULL)
		{
			free(M->Data[0]);
			free(M->Data[1]);
			successfull_OR_NOT = Not_successfull;
		}
		else
		{
		M->Mailbox_DataSize=size;
		}
	return successfull_OR_NOT;
}


/***********************************************************************************************************************************
*Description: this function is used to Send Massege to mail-box 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 			
*@pram		: DataType 	--> void pointer to pointer locating data Address 	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege -note if bytes Sended Less than data Size Sended will Result in Garbage Value 
*
*@return	: SMS enum value either holding (Fail) could not Send OR  (Success) Send Done 
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
			M->Mailbox_Send_flag=full;
			if(M->Mailbox_Receive_flag==empty)
			{
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
			}
			else if(M->Mailbox_Receive_flag==full)
			{
				if(M->Mailbox_SBF==full)
				{
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
				}
				else
				{
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
				}
			}
				M->Mailbox_Send_flag=empty;
				ReturnState =Success;
		}
	return ReturnState;
}

/***********************************************************************************************************************************
*Description: this function is used to Receive Massege from mail-box 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created
*@pram		: DataType 	--> void pointer to pointer locating Address to Put Data into	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege Received - note data max size is Max Created bytes in Create any more will be overlooked.
*
*@return	: void 
************************************************************************************************************************************/
void OS_VidMailbox_Receive(Mailbox *M,void *copy_of_data_type,Size data)
{
	u8 *ptr = (u8*) copy_of_data_type;
		if(M->Mailbox_Send_flag == empty) 
		{
			M->Mailbox_Receive_flag=full;
			
			if(M->Mailbox_SBF==full)
			{
				
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
			}
			M->Mailbox_Receive_flag=empty;
		}
		else(M->Mailbox_Send_flag == full)
		{
			M->Mailbox_Receive_flag=full;
			if(M->Mailbox_SBF==full)
			{
				
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
			}
			else
			{
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
			}
			M->Mailbox_Receive_flag=empty;
		}
}
