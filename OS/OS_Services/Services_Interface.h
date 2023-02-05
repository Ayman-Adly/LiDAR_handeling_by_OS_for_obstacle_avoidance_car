#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H

typedef struct 
{
	u8 		Mailbox_Receive_flag;
	u8 		Mailbox_Send_flag;
	u8 		Mailbox_SBF;
	u8		Mailbox_DataSize;
	void	**Data[2];
}Mailbox;

/************************************************************************************************************************************/
/************************************************ Public Macros ******************************************************************/
/************************************************************************************************************************************/

typedef enum{
	Fail=0,
	NotReserved=0,
	SuccessNotReserved=1,
	Reserved=1,
	SuccessandReserved=2
}SendM;


typedef enum{
	Not_successfull,
	successfull
}MBS;

typedef enum{
	empty=0,
	full=1
}state;

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
*@return		: u8 value either holding u8 number (1) location Reserved OR  ERROR could not Reserve location (0)	
************************************************************************************************************************************/	
u8 Mailbox_Create(Mailbox *M,Size data);


/***********************************************************************************************************************************
*Description: this function is used to Send Massege to mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created 			
*@pram		: DataType 	--> void pointer to pointer locating data Address	
*@pram		: Size 		--> Size of bytes needed to hold data  OR Size of Massege
*
*@return		: u8 value either holding (0) could not Send OR  (1) Send Done successfully but Data not Reserved  OR (2) Send Done successfully & Data Reserved
************************************************************************************************************************************/
u8 Mailbox_Send( Mailbox *M, void* *copy_of_data_type ,Size data);


/***********************************************************************************************************************************
*Description: this function is used to Receive Massege from mail-box in Run-Time
*Scope		: public
*@pram		: Mailbox	--> Address of Mailbox created
*
*@return		: DataType --> void pointer holding Address of Massege Data (trying to cast the recive pointer to more data bytes than sended value can result in garbage Value)
************************************************************************************************************************************/
DataType Mailbox_Receive( Mailbox *M);

#endif
