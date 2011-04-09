#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    char str[20] = "This is a C world!";
    char *p = str;
    char *p1= str;
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
    p=p1=str;
    while(*p != '\0')
    { 
       while(*p1 == ' ') p1++;
        if (p != p1)
         {
            *p = *p1;
         }
       p1++;
       p++;
   }

   *p = '\0';
   puts(str);

    return 0;
}
