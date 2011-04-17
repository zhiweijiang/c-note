#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int number;
    char name[20];
    char score;
    struct node *next;
};

typedef struct node V_NODE;
V_NODE *create_link(int n);
void print_link(V_NODE *p);
V_NODE * add_link(V_NODE * head);


int main(int argc, const char *argv[])
{
    V_NODE *head;
    int n = 0;
    printf("Input a number:");
    scanf("%d", &n);

    head = create_link(n);
    print_link(head);    
    head = add_link(head);
    print_link(head);

    return 0;
}


V_NODE *create_link(int n)
{
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    int i = 0;
    p = head = malloc(sizeof(V_NODE));
    if(p == NULL)
    {
        perror("malloc");
        exit (0);
    }
    p->number = 1;
    strcpy(p->name,"a");
    p->score = 'a';
    p->next = NULL;
    for (i = 1; i < n; i++) 
    {
        p->next = malloc(sizeof(V_NODE));
        if(p->next == NULL)
        {
            perror("malloc");
            exit(0);
        }
        p->next->number = 2*i+1;
        strcpy(p->next->name,"a");
        p->next->score = 'a';
        p->next->next = NULL;
        p = p->next;
    }
    
    return head;
}


void print_link(V_NODE *p)
{
    while(p != NULL)
    {
        printf("%d\t%s\t%c\n", p->number, p->name, p->score);
        p = p->next;
    }
}

V_NODE * add_link(V_NODE * head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;
    p = malloc(sizeof(V_NODE));
    if(!p)
    {
        perror("malloc");
        exit(0);
    }
    printf("Input  number:");
    scanf("%d", &p->number);
    printf("Input name:");
    scanf("%s", p->name);
    getchar();
    printf("Input score:");
    scanf("%c", &p->score);
    p->next = NULL;
    if(!ptr)
    {
        return p;
    }
    if(p->number < ptr->number)
    {
        p->next = ptr;
        head = p;
        return head;
    }
    while((ptr->next != NULL)&&(p->number > ptr->next->number))
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;

    return head;


}
