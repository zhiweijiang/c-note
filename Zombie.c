#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int status;

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid > 0)
    {  
        kill(pid, SIGINT);
        wait(&status);
        if(WIFEXITED(status))
            printf("THe return status is %d\n", WEXITSTATUS(status));
        else if(WIFSIGNALED(status))
            printf("The sign is %d\n", WTERMSIG(status));
     // while(1);
    }
     if(0 == pid)
    {
        sleep(5);
    }

    return 0;
}
