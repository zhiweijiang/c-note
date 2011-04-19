#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
    int number = 0;
    char *p;
/*  char str[20];
    int base = 0;
    
    printf("input the number:\n");
    scanf("%s", str);
    printf("input the base\n");
    scanf("%d", &base);         */
    number = strtol(argv[1], &p,atoi(argv[2]));
    printf("the result:%d\n", number);

    return 0;
}
