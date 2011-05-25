#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int fd[2];
    pid_t pid;
    int stat_val;

    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0)
    {
        close(fd[0]);
        sleep(1);
        waitpid(pid, &stat_val, 0);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else if(WIFSIGNALED(stat_val))
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }
    else
    {
         close(fd[0]);
         sleep(1);
         write(fd[1], "hello workd\n", 12);
    }

    return 0;
}
