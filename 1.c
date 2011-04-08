#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    int d = 0, i =0; 
    unsigned int mask = (0x01) << (sizeof(int)* 8 - 1);
    puts("Please input a number :");
    scanf("%d", &d);
    puts("result");
    for (i = 0; i < 32; i++)
    {
        printf("%d",((d&mask)!= 0 ? 1 : 0));
        mask >>= 1;
    }
    printf("\n");
    return 0;
}
