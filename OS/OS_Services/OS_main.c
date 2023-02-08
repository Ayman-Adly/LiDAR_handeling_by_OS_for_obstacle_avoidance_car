#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"
#include"MailBox_Interface.h"


int main(void)
{
	u8 Arr[10]={0,0,1,3,4,5,6,7,8,9};
	u32 Receive=0;
	u8 sizestate;
	u8 mailbox_status=0,status=0;
	Mailbox x;
	mailbox_status=OS_enuMailbox_Create(&x,10);
	printf("\nvalue either holding enum number (1) location Reserved OR  ERROR could not Reserve location (0)\nmailbox_status=%d\n",mailbox_status);
	status=OS_enuMailbox_Send(&x,&Arr,8);
	printf("\nu8 value either holding (0) could not Send OR  (1) Send Done successfully\nstatus= %d\n",status);
	OS_VidMailbox_Receive(&x,&Receive,3);
	printf("\nReceived Data = %d",Receive);
	
	
	
	return 0;
}
