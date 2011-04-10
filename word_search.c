#include <stdio.h>
#include <string.h>


void word_search(char *p, char *q);

int main(int argc, const char *argv[])
{
 
    char Article[50]="This is a word search function";
    char word[10];

    puts("Please inpuot a word of you want to search:");
    scanf("%s",word); 
    word_search(Article, word);
    return 0;
}


void word_search(char *p, char *q)
{
 
    char *p1=p;
    char *q1=q;
    int i = 0;
    int j = 0;

    while( *p !='\0')
        {
            j= 0;
            p1=p;
            q1=q;
            while(*q1!='\0')
            {
             if(*p1 == *q1)
             j++;
             else
             break;
             if(j+1==strlen(q))
             {
             printf("The word Position in the article:%d\n",i);
            return;
             }
            q1++;
            }
            p++;
            i++;
        }
        if(*p == '\0')
            printf("Search no the word in the article!!\n");
} 
    
