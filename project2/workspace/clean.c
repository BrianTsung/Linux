#include <linux/kernel.h>
#include "variable.h"
#include <linux/sched.h>
#include <asm/current.h>
asmlinkage long clean_wait_queues(int x)
{
//sleeping_task=current;
int i=0;
if (x==1)
{
for (i=0;i<count;i++)
{
project2_queue_1[i]=0;
wake_up_process(current_array[0][i]);
}
count=0;
}
if (x==2)
{
for (i=0;i<count2;i++)
{
project2_queue_2[i]=0;
wake_up_process(current_array[1][i]);
}
count2=0;
}
if (x==3)
{
for (i=0;i<count3;i++)
{
project2_queue_3[i]=0;
wake_up_process(current_array[2][i]);
}
count3=0;
}
set_current_state(TASK_RUNNING);

printk("%d,%d,%d",count,count2,count3);
return x;
}

