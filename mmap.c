#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int *p;
    int fd = open("hello", O_RDWR);
    if(fd < 0)
    {
        perror("fd");
        exit(0);
    }
    p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        exit(0);
    }
    close(fd);
    p[1] =(int) 0x30313233;
    munmap(p, 6);

    return 0;
}
