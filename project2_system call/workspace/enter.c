#include <linux/kernel.h>
#include "variable.h"
#include <linux/sched.h>
#include <asm/current.h>
int project2_queue_1[1000]={0};
int project2_queue_2[1000]={0};
int project2_queue_3[1000]={0};
int count=0,count2=0,count3=0;
struct task_struct *current1;
struct task_struct *current_array[3][10];
asmlinkage long enter_wait_queue(int x){
  if (x==1){
    project2_queue_1[count]=1;
    current_array[0][count]=current;
    count+=1;
  }
  if (x==2){
    project2_queue_2[count2]=1;
    current_array[1][count2]=current;
    count2+=1;
  }
  if (x==3){
    project2_queue_3[count3]=1;
    current_array[2][count3]=current;
    count3+=1;
  }
  printk("%d,%d,%d",count,count2,count3);
  set_current_state(TASK_INTERRUPTIBLE);
  current1=current;
  schedule();
  return x;
}
