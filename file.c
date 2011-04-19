#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char *str = "hello!";
    char str_1[20];

    fp = fopen("text2", "w+");
    if(!fp)
    {
        perror("open");
        exit(0);
    }
//  fprintf(fp, "%s\n", str);
    fscanf(fp, "%s", str_1);
    printf("str_1:%s\n", str_1);
    fclose(fp);

    return 0;
}
