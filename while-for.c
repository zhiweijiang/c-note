#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i;
    int n = 5;

    for (i = 0; i < n; i++) 
    {
        printf("a\n");
        continue;    
    }
    i = 0;
    getchar();
    while(i<10)
    {
        printf("aa\n");
        continue;
        i++;
    }

    return 0;
}
