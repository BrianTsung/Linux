#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int main(void){
  int random_num;
  int pid,count1,count2,count3;
  int i;
  char str[300];
  struct timeval t1,t2;

  gettimeofday(&t1,NULL);

  pid=getpid();
  srand(time(NULL)+pid);
  count1=0;
  count2=0;
  count3=0;

  char pid_str[12];
  sprintf(pid_str, "%d", pid);

  char filename[17] = "file_";
  strcat(filename, pid_str);
  strcat(filename, ".txt");

  printf("%s\n", filename); 

  for (i=1;i<=3;i++){
    gettimeofday(&t2,NULL);
    random_num=(rand()%3)+1;
    FILE *fptr;
    fptr = fopen(filename,"a");
    if (random_num==1){
      count1++;
      sprintf(str,"process %d is added into wait queue project2_queue_%d the %d th time at time %ld \n",pid,random_num,count1,t2.tv_sec);
    }
    if (random_num==2){
      count2++;
      sprintf(str,"process %d is added into wait queue project2_queue_%d the %d th time at time %ld \n",pid,random_num,count2,t2.tv_sec);
    }
    if (random_num==3){
      count3++;
      sprintf(str,"process %d is added into wait queue project2_queue_%d the %d th time at time %ld \n",pid,random_num,count3,t2.tv_sec);
    }
  fprintf(fptr,"%s",str);
  fclose(fptr);
  long retval=syscall(352,random_num);
  if (retval!=random_num)
    printf("0:add into wait queue error\n");
  else
    printf("1:add into wait queue successful\n");
  }
  return 1;
}

