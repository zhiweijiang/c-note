#include <stdio.h>
#include <string.h>

void longest_substring(char *src, char *dest);

int main(int argc, const char *argv[])
{
    char str[20];
    char str1[20];

    puts("Plese input two string:");
    fgets(str,20,stdin);
    fgets(str1,20, stdin);
    if(strlen(str) >= strlen(str1))
    {
        longest_substring(str, str1);
    }    
    else
    {
        longest_substring(str1, str);
    }

    return 0;
}

void longest_substring(char *src, char *dest)
{
    char *p = src;
    char *q = dest;
    int length = 0;
    int a = 0;

     for ( ; *src != '\n'; src++) 
     {
         for(q = dest, p = src; *q != '\n'; q++,p++)
          {
             if(*p == *q)
             {
              length ++;
             }
          }
         if(a <= length)
           a = length;
         length = 0;
     }
     printf("the longest public substring is:%d\n", a);

}
