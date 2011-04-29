#include <stdio.h>

void delete_char(char *str, char ch);


int main(int argc, const char *argv[])
{
    char str[]="abcedefhai";
    char ch = 'a';

    printf("%s\n", str);
    delete_char(str, ch); 
    return 0;
}


void delete_char(char *str, char ch)
{
    char *p = str;
    char *q = str;


   for (; *str != '\0'; str++) 
    {
        if(*str != ch)
            {
            *p = *str;
            p++;
            }
    }
    *p = '\0';
    printf("%s\n",q);
}
