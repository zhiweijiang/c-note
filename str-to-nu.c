#include <stdio.h>
#include<string.h>

void str_to_number(char *s );

int main(int argc, const char *argv[])
{
    char str[100] = "This is string to number:string1234to number1234";
        
        str_to_number(str);
        return 0;
}



void str_to_number(char *s )
{
     
     int number = 0;
     
     while(*s != '\0')
      {

          if((*s > '0') && (*s < '9'))
         {
     
           number = *s - 0x30;
           s = s + 1;
           while((*s > '0') && (*s < '9'))
          {
             number = number * 10;
             number = number + (*s - 0x30);
             s++;
          }
            printf("The number:%d\n", number);
        } 
        s++;
      }
      if( number == 0)
      printf("No number in the string!\n");
}
