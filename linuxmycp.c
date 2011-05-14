#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void linuxmycp(char *src, char *des);

int main(int argc, const char *argv[])
{

    if(argc != 3)
    {
        printf("please input 2 file name!!\n");
        exit(0);
    }
    linuxmycp(argv[1], argv[2]);    
    return 0;
}

void linuxmycp(char *src, char *des)
{
    char buf[1024];
    int n;
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    fp1 = open(src, O_RDONLY);
    if(fp1 < 0)
    {
        perror("fp1");
        exit(0);
    }
    fp2 = open(des, O_WRONLY|O_CREAT, 0644);
    if(fp2 < 0)
    {
        perror("fp2");
        exit(0);
    }
    while(n = read(fp1, buf, 1024))
    {
        write(fp2, buf, n);
    }
    close(fp1);
    close(fp2);

}


