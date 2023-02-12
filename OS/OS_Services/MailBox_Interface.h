#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H

typedef struct 
{
	u8 		Mailbox_Receive_flag;
	u8 		Mailbox_Send_flag;
	u8 		Mailbox_SBF;
	u8		Mailbox_DataSize;
	u8		*Data[2];
}Mailbox;

/************************************************************************************************************************************/
/************************************************ Public Macros ******************************************************************/
/************************************************************************************************************************************/

typedef enum{
	Fail=0,
	Success=1
}SMS;//send Massege state


typedef enum{
	Not_successfull,
	successfull
}MBS;//mailbox state

typedef enum{
	empty=0,
	full=1
}state; //state of massege

typedef enum{
	One_byte=1,
	two_bytes=2,
	Three_bytes=3,
	Four_bytes=4,
	Five_bytes=5,
	Six_bytes=6,
	Seven_bytes=7,
	Eight_bytes=8
}Size;

typedef void* DataType;

/************************************************************************************************************************************/
/************************************************ Public Functions ******************************************************************/
/************************************************************************************************************************************/

/***********************************************************************************************************************************
*Description: this function is used to create a mail-box data size in run-time 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 	
*@pram		: Size 		--> Size of bytes needed to hold data 
*
*@return	: MBS enum value either holding (successfull)-->(1) location Reserved OR  ERROR could not Reserve location (Not_successfull)-->(0)	
************************************************************************************************************************************/	
MBS OS_enuMailbox_Create(Mailbox *M,Size data);


/***********************************************************************************************************************************
*Description: this function is used to Send Massege to mail-box 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 			
*@pram		: DataType 	--> void pointer to pointer locating data Address 	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege -note if bytes Sended Less than data Size Sended will Result in Garbage Value 
*
*@return	: SMS enum value either holding (Fail) could not Send OR  (Success) Send Done 
************************************************************************************************************************************/
SMS OS_enuMailbox_Send( Mailbox *M, void *PointerToDataSended ,Size data);


/***********************************************************************************************************************************
*Description: this function is used to Receive Massege from mail-box 
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created
*@pram		: DataType 	--> void pointer to pointer locating Address to Put Data into	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege Received - note data max size is Max Created bytes in Create any more will be overlooked.
*
*@return	: void 
************************************************************************************************************************************/
void OS_VidMailbox_Receive( Mailbox *M,void *PointerToDataRecived,Size data);

#endif
