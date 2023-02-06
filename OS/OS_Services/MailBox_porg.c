#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"

#include"Services_Priv.h"
#include"Services_Interface.h"



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
			*M->Data[empty]=0;//initilaze value to zero
			*M->Data[full]=0;//initilaze value to zero
		}
	return successfull_OR_NOT;
}

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


DataType OS_VPMailbox_Receive(Mailbox *M)
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
