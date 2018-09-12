#include<stdio.h>
#include<stdlib.h>

void create();
void display();

void add_beg();  
void add_end();

void delete_beg();
void delete_end();

struct node
{
    int data;
    struct node *next,*previous;
};

struct node *start=NULL,*ptr;

int main()
{
    int option;
    
    do
    {
        printf("\n1.Create doubly linked list\n");
        printf("2.Display\n");
        printf("3.Add at begining\n");
        printf("4.Add at end\n");
        printf("5.Delete begining\n");
        printf("6.Delete end\n");
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
            delete_beg();
            break;
            
            case 6:
            delete_end();
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
    newnode->data=e;
    newnode->next=NULL;
    newnode->previous=NULL;
    start=newnode;
}

void display()
{
    if(start==NULL)
    {
        printf("Underflow");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void add_beg()
{
   
    if(start==NULL)
    {
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        
        start=newnode;
        newnode->next=NULL;
        newnode->previous=NULL;
    }
    else
    {
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        
        newnode->next=start;
        newnode->previous=NULL;
        start=newnode;
    }
}

void add_end()
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);

    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->previous=ptr;
}

void delete_beg()
{
    if(ptr==start)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
}

void delete_end()
{
    struct node *preptr;
    if(ptr==start)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    }
}


