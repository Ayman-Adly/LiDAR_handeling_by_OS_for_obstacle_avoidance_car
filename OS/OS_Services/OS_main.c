#include<stdio.h>
#include<stdlib.h>

#include"LIB/STD_TYPES.h"
#include"MailBox_Interface.h"


int main(void)
{
	u16 p = 230;
	u8 sizestate;
	u8 mailbox_status=0,status=0;
	u16 *ptr;
	Mailbox x;
	mailbox_status=OS_enuMailbox_Create(&x,1);
	printf("\nvalue either holding enum number (1) location Reserved OR  ERROR could not Reserve location (0)\nmailbox_status=%d\n",mailbox_status);
	status=OS_enuMailbox_Send(&x,(void *)&p,1);
	printf("\nu8 value either holding (0) could not Send OR  (1) Send Done successfully\nstatus= %d\n",status);
	ptr=OS_VPMailbox_Receive(&x);
	printf("\nDataType --> void pointer holding Address of Massege Data (trying to cast the recive pointer to more data bytes than sended value can result in garbage Value)\nData received=%d\n",*ptr);
	
	printf("P Address=%u\n",&p);
	printf("ptr Address=%u\n",ptr);
	//printf("%d\n",*(u16*)ptr);
	
	return 0;
}
