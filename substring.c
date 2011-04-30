#include <stdio.h>

void longest_substring(char *src, char *dest);

int main(int argc, const char *argv[])
{
    char str[20];
    char str1[20];

    puts("Plese input two string:");
    fgets(str,20,stdin);
    fgets(str1,20, stdin);
    puts("the two string:");
    printf("%s%s", str, str1);
    longest_substring(str, str1);
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
        q = dest;
         p = src;       
             for(; *q != '\n'; q++)
             {
                while(*q != *p)q++;
                 if(*p == *q)
                 {
                 length ++;printf("%d\n",length);
                 p++;
                 }
                 else
                 {
                 length = 0;
                 q--;
                 p=src;
                 }
                 if(a<=length)
                  a = length;
             }
     }
     printf("the longest public substring is:%d\n", a);

}
