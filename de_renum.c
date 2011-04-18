#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int a[10] = {0};
    char str[20];
    int k = 0;
    int j = 0;
    int i = 0;
    
    printf("Please input a number string:");
    scanf("%s", str);
    printf("Before delete renumber:");
    printf("%s\n", str);
    for(i = 0; str[i]!='\0'; i++)
    {
        k = str[i] - 0x30;
        if(0 == a[k])
            a[k] = 1;
        else
          { 
            for(j = i; str[j] !='\0';j++)
            {
                 str[j]=str[j+1];
            }
            i--;
          }
     }
     printf("After delete renumber:");
     printf("%s\n", str);

    return 0;
}
