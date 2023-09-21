#include <43func.h>
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("I am child, pid = %d, ppid = %d\n", getpid(), getppid());
    }
    else
    {
        printf("I am parent, pid = %d, ppid = %d\n", getpid(), getppid());
    }
}