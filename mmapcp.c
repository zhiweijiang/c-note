#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, const char *argv[])
{   
    int *pi, *po;
    struct stat length;
    int fd_in = open(argv[1], O_RDONLY);
    int fd_out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
    
    if(fd_in <0 || fd_out < 0)
    {
        perror("open fail");
        exit(1);
    }
    if(fstat(fd_in, &length) == -1)
    {
        perror("fstat");
        exit(0);
    } 

    lseek(fd_out, length.st_size-1, SEEK_SET);
    write(fd_out, "", 1);

    pi = mmap(NULL, length.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    po = mmap(NULL, length.st_size, PROT_WRITE, MAP_SHARED, fd_out, 0);
    if( pi == MAP_FAILED || po == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    memcpy(po,pi, length.st_size);
    
    close(fd_in);
    close(fd_out);
    munmap(pi, length.st_size);
    munmap(po, length.st_size);
    
    return 0;
}
