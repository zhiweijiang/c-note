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

    fd = open("1.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }
    lseek(fd, 5, SEEK_SET);
    write(fd, "", 1);

    p = (char *)mmap(NULL, 10, PROT_NONE | PROT_WRITE, MAP_SHARED, fd, 0);
    if( p == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    for (i = 0; i < 10; i++) 
    {
        p[i] = i+'a';
    }
    printf("shared to success!\n");
    getchar();
    munmap(p, 10);

    return 0;
}
