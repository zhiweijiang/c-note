#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    char str[20] = "This is a C world!";
    char *p = str;
    char c_str[20];
    char *p_c = c_str;

    while(*p != '\0')
    {
       putchar(*(p++));  
    }
    printf("\n");
    while(p-- > str)
    {  
       putchar(*p);  
    }
    printf("\n");
    p=str;
    while(*p != '\0')
    {
        if (*p!=' ')
       {
       *p_c++=*p++;
       }
       else 
       p++;
   }
    *p_c='\0';
   puts(c_str);

    return 0;
}
