#include<stdio.h>
#include<stdlib.h>

void insert();
void del();

void display();
void peek();

struct node 
{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

int main()
{
    int option;
    
    do
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter option: ");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
            insert();
            break;
            
            case 2:
            del();
            break;
            
            case 3:
            peek();
            break;
            
            case 4:
            display();
            break;
        }
        
    }while(option!=5);
    
    return 0;
}

void insert()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    
    }
}

void del()
{
    if(front==NULL)
    {
        printf("Underflow\n");
    }
    else if(front==rear)
    {
        printf("Element %d has been deleted\n",front->data);
        free(front);
        front=rear=NULL;
    }
    else
    {
        struct node *temp;
        
        temp=front;
        front=front->next;
        printf("Element %d has been deleted\n",temp->data);
        free(temp);
    }
}

void peek()
{
    if(front==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d\n",front->data);
    }
}

void display()
{
    if(front==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        struct node *ptr;
        
        ptr=front;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}