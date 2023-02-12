#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"
#include"MailBox_Interface.h"


int main(void)
{
	u16 h=10;  //u16 --> u8+u8 
	u16 z=6;
	u32 Receive=0;
	u8 sizestate;
	u8 mailbox_status=0,status=0;
	Mailbox x;
	mailbox_status=OS_enuMailbox_Create(&x,6);
	printf("\nvalue either holding enum number (1) location Reserved OR  ERROR could not Reserve location (0)\nmailbox_status=%d\n",mailbox_status);
	status=OS_enuMailbox_Send(&x,&h,2);
	printf("\nu8 value either holding (0) could not Send OR  (1) Send Done successfully\nstatus= %d\n",status);
	OS_VidMailbox_Receive(&x,&Receive,2);
	printf("\nReceived Data = %d",Receive);
	
	
	return 0;
}
