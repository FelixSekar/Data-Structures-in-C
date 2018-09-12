#include<stdio.h>
#include<stdlib.h>

void create();
void display();

void add_beg();
void add_end();

void del_beg();
void del_end();

struct node 
{
    int data;
    struct node *next;
};

struct node *start=NULL,*ptr,*preptr;

int main()
{
    int option;
    
    do 
    {
        printf("\n\n1.Create circular linked list\n");
        printf("2.Display\n");
        printf("3.Add begining\n");
        printf("4.Add end\n");
        printf("5.Delete beg\n");
        printf("6.Delete end\n");
        printf("7.Exit\n");
        printf("Enter option\n");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
            create();
            break;
            
            case 2:
            display();
            break;
            
            case 3:
            add_beg();
            break;
            
            case 4:
            add_end();
            break;
            
            case 5:
            del_beg();
            break;
            
            case 6:
            del_end();
            break;
        }
    }while(option!=7);
    
    return 0;
}

void create()
{
    int e;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter data\n");
    scanf("%d",&e);
    start=newnode;
    newnode->data=e;
    newnode->next=start;
}

void display()
{
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d \n",ptr->data);
}

void add_beg()
{
    int e;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter data\n");
    scanf("%d",&e);
    newnode->data=e;
    newnode->next=start;
    
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    start=newnode;
    
}

void add_end()
{
    int e;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter data\n");
    scanf("%d",&e);
    newnode->data=e;
    newnode->next=start;
    
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
}

void del_beg()
{
    struct node *del_ptr=start;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    start=start->next;
    free(del_ptr);
}

void del_end()
{
    ptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=start;
    free(ptr);
}
