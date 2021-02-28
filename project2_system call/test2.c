#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void delay(int secs){
  int retTime=time(0)+secs;
  while(time(0)<retTime);
}

int main(void){
  delay(3);
  int i;
  int pid;
  pid=getpid();
  srand(time(NULL));
  int random_num;

  char pid_str[12];
  sprintf(pid_str, "%d", pid);
  char filename[17] = "fileyayaya_";
  strcat(filename, pid_str);
  strcat(filename, ".txt");
  FILE *fptr;
  fptr = fopen(filename,"a");
  for (i=1;i<=18;i++){
    random_num=(rand()%3)+1;
    long retval2=syscall(353,random_num);
    if (retval2!=random_num)
      printf("0:wake up error\n");
    else
      printf("1: %dwake up successful\n", random_num);
    fprintf(fptr,"project2_queue%d wake up\n",random_num);
    delay(2);
  }
  syscall(353,1);
  syscall(353,2);
  syscall(353,3);
  fclose(fptr);
  return 1;
}
