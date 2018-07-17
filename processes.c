#include <stdio.h>
#include <unistd.h>

 int main() {
  int pid;
  printf("Am the parent process with PID %d and PPID %d \n",getpid(), getppid() );
  pid = fork();

  if(pid > 0)
  {
    printf("Am the parent process with PID %d and PPID %d \n",getpid(), getppid() );
    printf("My child is of PID %d\n", pid);
  }
  else if(pid == 0)
  {
    printf("Am the child process with PID %d\n", getpid());
  }
  else{
    perror("Fork Error!");
  }
  return 0;
}
