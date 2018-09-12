#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();
void peek();

struct node 
{
    int data;
    struct node *next;
};

struct node *top=NULL;

int main()
{
    int option;
    
    do
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter option\n");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
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

void push()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}

void pop()
{
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct node *temp;
        
        temp=top;
        top=top->next;
        printf("The element %d has been popped",temp->data);
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct node *ptr;
        
        ptr=top;
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d\n",top->data);
    }
}