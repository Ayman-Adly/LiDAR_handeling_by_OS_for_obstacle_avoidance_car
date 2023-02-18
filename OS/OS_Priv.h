

#define TIMER_INITIAL_COUNT (0U)


typedef struct TaskInfo_t
{
	u8 Priority		   ;
	u16 periodicity        ;
	void (*TaskFunc)(void) ;
	TaskState_t TaskState  ;
	u16 FirstDelay	   	   ;
	u16 task_ID             ;
}TaskInfo_t;

typedef struct Task_t
{
	TaskInfo_t Task		   ;
	struct Task_t *Next	   ;	
}Task_t;



static void vidSchedular(void);


