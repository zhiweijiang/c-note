#include <stdio.h>

int main(int argc,  char *argv[])
{
    char **ptr=argv;
    int i = 0;  
    int a[2][3]={{0,2},{34}};
    int (*p)[3] = a;
    for (i = 0; i < 2; i++) 
    {
    printf("%d\n",(*(p+i))[0]);
    }
    for (i = 0; i < argc; i++) 
    {
        printf("%s\n",*(ptr+i));
    }
    return 0;
}
