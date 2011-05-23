#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    
    if(argc != 2)
    {
        perror("argc");
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    execl("./upper", "upper", NULL);
    perror("exec./upper");
    exit(1);

    return 0;
}
