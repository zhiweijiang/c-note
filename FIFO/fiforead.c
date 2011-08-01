#include <stdio.h>
#include <sys/types.h> #include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, const char *argv[])
{
    int fd, n;
    char buf[4096];
    if((fd = open("./hello", O_RDWR)) < 0)
    {
        perror("open");
        exit(1);
    }
    n = read(fd, buf, 4096);
    if(n < 0)
    {
        perror("read");
        exit(1);
    }
    printf("read data is : %s\n", buf);

    close(fd);
    return 0;
}
