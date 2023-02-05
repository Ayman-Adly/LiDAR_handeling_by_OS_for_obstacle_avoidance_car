#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"

#include"Services_Priv.h"
#include"Services_Interface.h"



u8 Mailbox_Create(Mailbox *M,Size	size)
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
		M->Mailbox_DataSize=size;
		*M->Data[empty]=NULL;
		*M->Data[full]=NULL;
	return successfull_OR_NOT;
}

u8 Mailbox_Send(Mailbox *M,void**copy_of_data_type,Size data)
{
		u8 ReturnState;  // 0(Fail)   or   1(SuccessNotReserved)  OR 2 (SuccessandReserved)
		void *ptr[2];
		if(M->Mailbox_Send_flag == full) 
		{
			ReturnState = Fail;
		}
		else if(M->Mailbox_Send_flag == empty)
		{
			if(M->Mailbox_DataSize!=data)
			{
				ptr[empty]=malloc(data);
				ptr[full]=malloc(data);	
					if(ptr[empty]!=NULL&&ptr[full]!=NULL)
				{
					free(M->Data[empty]);
					free(M->Data[full]);
					M->Data[empty]=ptr[empty];
					M->Data[full]=ptr[full];
					ReturnState=Reserved;
					M->Mailbox_DataSize=data;
				}
				else
				{
					ReturnState=NotReserved;
				}
			}
			if(M->Mailbox_Receive_flag==empty)
			{
				M->Mailbox_Send_flag=full;
				switch(M->Mailbox_DataSize)
				{
					case One_byte:		*(u8*)M->Data[empty]=*(u8*)copy_of_data_type 		;break;
					case two_bytes:		*(u16*)M->Data[empty]=*(u16*)copy_of_data_type 		;break;
					case Three_bytes:
					case Four_bytes:	*(u32*)M->Data[empty]=*(u32*)copy_of_data_type 		;break;
					case Five_bytes:
					case Six_bytes:
					case Seven_bytes:
					case Eight_bytes:	*(f64*)M->Data[empty]=*(f64*)copy_of_data_type 		;break;
				}
				M->Mailbox_Send_flag=empty;
				ReturnState =ReturnState+SuccessNotReserved;
			}
			else if(M->Mailbox_Receive_flag==full)
			{
				M->Mailbox_Send_flag=full;
				switch(M->Mailbox_DataSize)
				{
					case One_byte:		*(u8*)M->Data[full]=*(u8*)copy_of_data_type 		;break;
					case two_bytes:		*(u16*)M->Data[full]=*(u16*)copy_of_data_type 		;break;
					case Three_bytes:
					case Four_bytes:	*(u32*)M->Data[full]=*(u32*)copy_of_data_type 		;break;
					case Five_bytes:
					case Six_bytes:
					case Seven_bytes:
					case Eight_bytes:	*(f64*)M->Data[full]=*(f64*)copy_of_data_type 		;break;
				}
				M->Mailbox_SBF=full;
				M->Mailbox_Send_flag=empty;
				ReturnState = ReturnState+SuccessNotReserved;
			}
		}
	return ReturnState;
}


DataType Mailbox_Receive(Mailbox *M)
{
	DataType Return;
		if(M->Mailbox_Send_flag == empty) 
		{
			if(M->Mailbox_SBF==full)
			{
				M->Mailbox_Receive_flag=full;
				Return=M->Data[full];
				M->Mailbox_Receive_flag=empty;
				M->Mailbox_SBF=empty;
			}
			else
			{
				M->Mailbox_Receive_flag=full;
				Return=M->Data[empty];
				M->Mailbox_Receive_flag=empty; // to test functionality
			}
		}
		
		return Return;
}
