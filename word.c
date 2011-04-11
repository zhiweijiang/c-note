#include <string.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[100]="This  is only a Game !";
    char *p = str;

    p = strtok(p, " ");
    while(p != NULL)
   {
        printf("%s\n",p);        
        p = strtok(NULL," ");
   }
    return 0;
}
