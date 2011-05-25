#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, const char *argv[])
{
    int fd, n;
    
    if((fd = open("./hello", O_RDWR)) < 0)
    {
        perror("open");
        exit(1);
    }
    n = write(fd, "hello,world!\n",13);
    if(n < 0)
    {
        perror("write");
        exit(1);
    }

    close(fd);
    return 0;
}
