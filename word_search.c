#include <stdio.h>
#include <string.h>
 

int  word_search(char *p, char *q);

int main(int argc, const char *argv[])
{
 
    char Article[50]="This is a word search function";
    char word[10]="word";
    int num = word_search(Article,word);

    if(num < 0)
    {
        printf("No such word\n");
    }
    else
    {
        printf("The position:%d\n",num);
    }
    return 0;
}


int word_search(char *p, char *q)
{
 
    int i = 0;
    while(*p != '\0')
   {
    if(strncmp( p, q,strlen(q)-1) == 0)
        return i;
      p++;
      i++;
   }
   return -1;
} 
    
