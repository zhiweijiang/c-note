#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char str[100] = "welcom to creul world!";
    char str_1[100];
    FILE *fp;
    char a ='\0';
 
    fp = fopen("text3", "w+");
    if(!fp)
    {
        perror("open");
        exit(0);
    }
    fprintf(fp, "%s%c",str, a);
    fputs(str, fp);
    rewind(fp);
//  fseek(fp,-30l,2);
    fgets(str_1, 100, fp);
    printf("%s\n", str_1);
    
    return 0;
}
