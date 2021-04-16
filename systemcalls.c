#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
int ret = 1;
int status;
pid = fork();
if (pid == -1)
{
printf("can't fork, error occured\n");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
printf("child process, pid = %u\n", getpid());
printf("parent of child process, pid = %u\n", getppid());
char *argv_list[] = {"ls", "-lart", "/home", NULL};
execv("ls", argv_list);
exit(0);
}
else
{
printf("Parent Of parent process, pid = %u\n", getppid());
printf("parent process, pid = %u\n", getpid());