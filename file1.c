#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char str[100] = "hello world\nthis is C world\n";
    int c;
    int i = 0;
    
    fp = fopen("text1","r+");
    if(fp == NULL)
    {
        perror("open");
        exit(0);
    }
    i = 0;
    while(str[i])
    {
        putc(str[i++], fp);
    }
    rewind(fp);
    i = 0;
    while((c = getc(fp)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fp);

    return 0;
}
