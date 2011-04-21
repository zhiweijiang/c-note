#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char str[1024];
    FILE *fp1;
    FILE *fp2;
    int n = 0;
    int i = 0;

    fp1 = fopen("text4", "r+");
    if(!fp1)
    {
        perror("open");
        exit(0);
    }
    fp2 = fopen("text5", "w+");
    if(!fp2)
    {
        perror("open");
        exit(0);
    }
    while(!feof(fp1))
    {
        n += fread(&str[n], 1, 4, fp1);
        i += 4;
    }
    fwrite(&str[0], 1, n, fp2);
    printf("i = %d\t n = %d\n", i , n);
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
