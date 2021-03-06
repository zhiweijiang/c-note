#include <stdio.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    
    pid = fork();
    if(pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    if(0 == pid)
    {
        int i;
        for (i = 0; i < 3; i++) 
        {
            printf("This is the child\n");
            sleep(1);
        }
        exit(3);
    }
    else
    {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else if(WIFSIGNALED(stat_val))
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }

    return 0;
}
