#include <stdio.h>


void hanoi(char a, char b, char c, int n);

int main(int argc, const char *argv[])
{
    int n = 0;
    printf("Please input the number:\n");
    scanf("%d", &n);
    puts("The result:");
    hanoi( 'A', 'B', 'C', n);
    return 0;
}


void hanoi(char a, char b, char c, int n)
{
        if(n == 1)
        {
            printf("%c------->%c\n", a, c);
            return ;
        }
        hanoi( a, c, b, n-1);
        printf("%c------->%c\n", a, c);// the last
        hanoi( b, a, c, n-1);
}
