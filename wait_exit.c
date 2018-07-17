#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {

  int pid,childpid,status;
  pid = fork();

  if(pid == 0)
  {
    printf("Am the child PID %d of PPID %d \n",getpid(), getppid() );
    printf("Child sleeping for 10 seconds.\n");
    sleep(10);
    exit(12);
  }
  else if(pid > 0)
  {
    printf("Am the parent process with PID %d and PPID %d \n",getpid(), getppid() );
    //waiting for child to terminate
    childpid = wait(&status);
    printf("A child of PID %d has terminated with status %d\n", childpid,status);
  }
  else{
    perror("Fork Failed!");
  }

  /* code */
}
