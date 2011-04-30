#include <stdio.h>
#include <string.h>

void mystrcpy(char *str, char *p);

int main(int argc, const char *argv[])
{
    char str[]="hello, world!";
    char p[20];
    p = str;

    mystrcpy(str, p);
    printf("%s\n", p);

    return 0;
}

void mystrcpy(char *str, char *p)
{
    
    for (;*str != '\0' ; str++) 
    {
        *p = *str;
        p++;
    }
    *p = '\0';
}
