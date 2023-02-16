

#define TIMER_INITIAL_COUNT (0U)


typedef enum
{
TASK_WAITING,
TASK_READY  
}TaskState_t;




typedef struct
{
	u8 Priority		   ;
	u16 periodicity        ;
	void (*TaskFunc)(void) ;
	TaskState_t TaskState  ;
	u16 FirstDelay	   	   ;
}TaskInfo_t;

typedef struct
{
	TaskInfo_t Task		   ;
	struct Task_t *Next	   ;	
}Task_t;



static void vidSchedular(void);


