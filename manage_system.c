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
void save_link(V_NODE *p);
V_NODE *load_link(void);
void print_test(void);

int main(int argc, const char *argv[])
{
    V_NODE *head = NULL;
    int flag = 0;
    
    print_test();
    head = load_link();
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
                save_link(head);
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
    printf("*\t4.save and exit         *\n");
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

void save_link(V_NODE *p)
{
    FILE *fp;
    fp = fopen("text", "w+");
    if(fp == NULL)
    {
        perror("open");
        exit(0);
    }
    while(p != NULL)
    {
        fprintf(fp, "%d\t%s\n", p->number, p->name);
        p = p->next;
    }
    fclose(fp);
}

V_NODE *load_link(void)
{
    FILE *fp;
    int num;
    char na[20];
    V_NODE *head = NULL;
    V_NODE *p;

    fp = fopen("text", "r+");
    if(fp == NULL)
    {
        perror("open");
        exit(0);
    }
    if(fscanf(fp, "%d%s", &num, na)!= EOF)
    {   
        p = malloc(sizeof(V_NODE));
        if(p == NULL)
        {
            perror("open");
            exit(0);
        }
        p->number = num;
        strcpy(p->name, na);
        p->next = NULL;
        head = p;
    }
    while(fscanf(fp, "%d%s", &num, na) != EOF)
    {
        p->next = malloc(sizeof(V_NODE));
        if(p->next == NULL)
        {
            perror("open");
            exit(0);
        }
        p->next->number = num;
        strcpy(p->next->name, na);
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}
