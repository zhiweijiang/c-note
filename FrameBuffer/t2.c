#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
    int fd;
    char *p;
    int i;

    fd = open("1.txt", O_RDWR);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    p = (char *)mmap(NULL, 10, PROT_NONE | PROT_WRITE, MAP_SHARED, fd, 0);
    if( p == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    for (i = 0; i < 10; i++) 
    {
        printf("%c", p[i]);
    }
    printf("\n");
    munmap(p, 10);

    return 0;
}
