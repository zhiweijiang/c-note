#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define MSG_TRY "try agin\n"

int main(int argc, const char *argv[])
{
    char buf[10];
    int fd, n;

    fd = open("dev/tty", O_RDONLY | O_NONBLOCK);
    if(fd < 0)
    {
        perror("open /dev/tty");
        exit(1);
    }
    tryagin:
        n = read(fd, buf, 10);
        if(n < 0)
        {
            if(errno == EAGAIN)
            {
                sleep(1);
                write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
                goto tryagin;
            }
            perror("read /dev/tty");
            exit(1);
        }
        write(STDOUT_FILENO, buf, n);
        close(fd);

    return 0;
}
