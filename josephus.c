#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node * next;
};

typedef struct node V_NODE;
V_NODE *init_link(int n);
void print_link(V_NODE *head, int n);
void game_doing(V_NODE *follow);

int main(int argc, const char *argv[])
{   
    V_NODE *head = NULL;
    V_NODE *rear = NULL;
    int n = 10;

    rear = init_link(n);
    head = rear ->next;
    print_link(head, n); 
    game_doing(rear);
    return 0;
}

V_NODE *init_link(int n)
{
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    int i = 0;
    
   
    p = head = malloc(sizeof(V_NODE));
    if(!p)
    {
        perror("malloc");
        exit(0);
    }
    p->number = 1;
    p->next = NULL;
    for (i = 1; i < n; i++) 
    {   
        p->next = malloc(sizeof(V_NODE));
        if(!p->next)
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = i+1;
        p->next->next = NULL;
        p = p->next;
    }
    p->next = head;
    
    return p;
}

void print_link(V_NODE *head, int n)
{   
    V_NODE *p = head;
    int i = 0;
    
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", p->number);
        p = p->next;
    }
    printf("\n");
}

void game_doing(V_NODE *follow)
{
    V_NODE *p = follow->next;
    int interval = 3;
    int counter = 0;
    
    printf("Input the interval:");
    scanf("%d", &interval);

    while(follow != follow->next)
    {
        counter ++;
        if(counter == interval)
        {
            printf("%4d(out)\t", p->number);
            follow->next = p->next;
            free(p);
            p = follow->next;
            counter = 0;
        }
        else
        {
            printf("%4d\t", p->number);
            p = p->next;
            follow = follow->next;
        }
        
    }
    printf("%4d left\n", follow->number);

}
