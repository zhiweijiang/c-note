#include <stdio.h>
#include <string.h>

int mystrcmp(char *dest, char (*src)[10], int num)
{
    int i;
    
    if(num == 0)
    {
        return 1;    
    }
    for (i = 0; i < num; i++) 
    {
        if(strcmp(dest, src[i])==0)
        return 0;
    }
    return 1;      
}


int main(int argc, const char *argv[])
{   
    char name[5][10];
    char tmp[10];
    int i;
    
    for (i = 0; i < 5; i++) 
    {
         printf("Please input a name:");
         fgets(tmp,10,stdin);
        if(mystrcmp(tmp, name,i)==1)
        strcpy(name[i],tmp);
        else 
        i--;
    }
    for (i = 0; i < 5; i++) 
    {                       
        printf("%s",name[i]);
    }
    return 0;
}
