#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char *str = "hello!";
    char str_1[20];
    int number[20] = {1,2,3,4,5};
    int number_1[20];
    fp = fopen("text2", "r+");
    if(!fp)
    {
        perror("open");
        exit(0);
    }
    fprintf(fp, "%s %d %d\n", str, number[0], number[1]);
    rewind(fp);
    fscanf(fp, "%s%d%d", str_1, &number_1[0], &number_1[1]);
    printf("str_1:%s %d %d\n", str_1, number_1[0], number[1]);
    fclose(fp);

    return 0;
}
