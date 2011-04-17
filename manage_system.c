#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    char name[20];
    struct node * next;
};

typedef struct node V_NODE;
V_NODE *add_link(V_NODE *head);
V_NODE *delete_link(V_NODE *head);
void print_link(V_NODE *p);
void print_list();
int  get_choice();

int main(int argc, const char *argv[])
{
    V_NODE *head = NULL;
    int flag = 0;

    while(!flag)
    {
       
        print_list();
        switch(get_choice())
        {
            case 1:
                head = add_link(head);
                break;
            case 2:
                head = delete_link(head);
                break;
            case 3:
                print_link(head);
                break;
            case 4:
                flag = 1 ;
                break;
            default :
                break;
        }
    }
    return 0;
}

int get_choice()
{
    char choice[20];

    printf("Please choose a number(1-4):");
    scanf("%s", choice);

    return atoi(choice);
}

void print_list()
{
    printf("*********************************\n");
    printf("*\t1.add_link              *\n");
    printf("*\t2.delete_link           *\n");
    printf("*\t3.print_link            *\n");
    printf("*\t4.exit                  *\n");
    printf("*********************************\n");
}


V_NODE *add_link(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;
    
    p = malloc(sizeof(V_NODE));
    if(!p)
    {
        perror("malloc");
        exit(0);
    }
    printf("Input number:");
    scanf("%d", &p->number);
    printf("Input name:");
    scanf("%s", p->name);
    p->next = NULL;
    if(!ptr)
    {
        return p;
    }
    if(p->number < ptr->number)
    {
        p->next = ptr;
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

V_NODE *delete_link(V_NODE *head)
{
    V_NODE * ptr = NULL;
    V_NODE *p = head;
    int num = 0;
    if(!p)
    {
        printf("Empty link,please create a link!\n");
        return head;
    } 
    printf("Please input delete number:");
    scanf("%d", &num); 
    if(p->number == num)
    {
        head = p->next;
        free(p);
        return head;
    }
    while((p->next != NULL)&&(p->next->number != num))
    {
        p = p->next;
    }
    if(!p->next)
    {
        printf("No match number!\n");
    }
    else
    {   
        ptr = p->next;
        p->next = p->next->next;
        free(ptr);
    }
    return head;
}

void print_link(V_NODE *p)
{   
    if(!p)
    {
        printf("Empty link,please create a link!\n");
        return;
    }
    while(p)
    {
        printf("number: %d\tname: %s\n", p->number, p->name);
        p = p->next;
    }
}
