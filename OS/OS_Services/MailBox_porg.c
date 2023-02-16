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
		u8 State = successfull;
		M->Mailbox_Receive_flag=Not_Receiving;
		M->Mailbox_Send_flag=Not_Sending;
		M->Mailbox_SBF=Not_Used;
		M->Data[empty] =(u8 *)malloc(size);
		M->Data[full] =(u8 *)malloc(size);
		if(M->Data[empty]==NULL||M->Data[full]==NULL)
		{
			free(M->Data[empty]);
			free(M->Data[full]);
			State = Not_successfull;
		}
		else
		{
			M->Mailbox_DataSize=size;
		}
	return State;
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
SMS OS_enuMailbox_Send(Mailbox *M,void *PointerToDataSended,Size SizeOfDataSended)
{
		u8 ReturnState;  // 0(Fail)   or   1(Success)
			
		if(PointerToDataSended==NULL)
		{
			ReturnState = Fail;
		}
		else
		{
			u8 *ptr =  (u8*)PointerToDataSended;
			if(M->Mailbox_Send_flag == Sending) 
			{
				ReturnState = Fail;
			}
			else if(M->Mailbox_Send_flag == Not_Sending)
			{
				M->Mailbox_Send_flag=Sending;
				if(M->Mailbox_Receive_flag==Not_Receiving)
				{
					if(SizeOfDataSended > M->Mailbox_DataSize)
					{
						//warning Massege	that i'll only save on Mailbox Size and data will overflow 
						
						for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
						{
							M->Data[empty][i] = *ptr++;
						}
					
					}
					else
					{
						for(u8 i=0 ; i < SizeOfDataSended ; i++ )
						{
							M->Data[empty][i] = *ptr++;
						}
					}
				}
				else if(M->Mailbox_Receive_flag==Receiving)
				{
					if(M->Mailbox_SBF==Used)
					{
						if(SizeOfDataSended > M->Mailbox_DataSize)
						{
							//warning Massege	that i'll only save on Mailbox Size and data will overflow
							for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
							{
								M->Data[empty][i] = *ptr++;
							}			
						}
						else
						{
							for(u8 i=0 ; i < SizeOfDataSended ; i++ )
							{
								M->Data[empty][i] = *ptr++;
							}
						}
					}
					else
					{
						if(SizeOfDataSended > M->Mailbox_DataSize)
						{
						//warning Massege	that i'll only save on Mailbox Size and data will overflow
							for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
							{
								M->Data[full][i] = *ptr++;
							}				
						}
						else
						{
							for(u8 i=0 ; i < SizeOfDataSended ; i++ )
							{
								M->Data[full][i] = *ptr++;
							}
						}
						M->Mailbox_SBF=Used;
					}
				}
					M->Mailbox_Send_flag=Not_Sending;
					ReturnState =Success;
			}
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
void OS_VidMailbox_Receive(Mailbox *M,void *copy_of_data_type,Size SizeOfDataRecived)
{
	u8 *ptr = (u8*) copy_of_data_type;
		if(M->Mailbox_Send_flag == Not_Sending) 
		{
			M->Mailbox_Receive_flag=Receiving;
			
			if(M->Mailbox_SBF==Used)
			{
				
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[full][i];
					}		
				}
				else
				{
					for(u8 i=0 ; i < SizeOfDataRecived ; i++ )
					{
						*ptr++= M->Data[full][i];
					}
				}
				M->Mailbox_SBF=Not_Used;
			}
			else
			{
				M->Mailbox_Receive_flag=Receiving;
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
				//warning Massege	that i'll only save on Mailbox Size and data will overflow 
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}
				}
				else
				{
					for(u8 i=0 ; i < SizeOfDataRecived ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}
				} 
			}
			M->Mailbox_Receive_flag=Not_Receiving;
		}
		else if(M->Mailbox_Send_flag == Sending)
		{
			M->Mailbox_Receive_flag=Receiving;
			if(M->Mailbox_SBF==Used)
			{
				
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}		
				}
				else
				{
					for(u8 i=0 ; i < SizeOfDataRecived ; i++ )
					{
						*ptr++= M->Data[empty][i];
					}
				}
			}
			else
			{
				if(SizeOfDataRecived > M->Mailbox_DataSize)
				{
					//warning Massege	that i'll only save on Mailbox Size and data will overflow
					for(u8 i=0 ; i < M->Mailbox_DataSize ; i++ )
					{
						*ptr++= M->Data[full][i];
					}		
				}
				else
				{
					for(u8 i=0 ; i < SizeOfDataRecived ; i++ )
					{
						*ptr++= M->Data[full][i];
					}
				}
			}
			M->Mailbox_Receive_flag=Not_Receiving;
		}
}