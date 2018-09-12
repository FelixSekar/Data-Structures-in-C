#include<stdio.h>  //header files                              
#include<stdlib.h>

void cr();          //function declarations

void add_beg();  
void add_end();
void add_aft();
void add_bef();

void del();
int del_aft();
int del_bef();

int nodes();

void sort();

void search();

void display();

struct node  //structure
{
    int data;
    struct node* next;
};

int e;
struct node* start=NULL;
struct node* ptr;
struct node* preptr;
struct node* postptr;

int main()
{
    int option,n;
    
    do
    {
        printf("\n1.Create linked list\n");
        printf("2.Add begining\n");
        printf("3.Add end\n");
        printf("4.Add after\n");
        printf("5.Add before\n");
        printf("6.Delete\n");
        printf("7.Delete after\n");
        printf("8.Delete before\n");
        printf("9.No. of nodes\n");
        printf("10.Sort\n");
        printf("11.Search\n");
        printf("12.Display\n");
        printf("13.Exit\n");
        printf("Enter option\n");
        scanf("%d",&option);
        
        switch(option)   //switch case
        {
            case 1:
            cr();
            break;
            
            case 2:
            add_beg();
            break;
            
            case 3:
            add_end();
            break;
            
            case 4:
            add_aft();
            break;
            
            case 5:
            add_bef();
            break;
            
            case 6:
            del();
            break;
            
            case 7:
            del_aft();
            break;
            
            case 8:
            del_bef();
            break;
            
            case 9:
            n=nodes();
            printf("\nNo. of nodes : %d\n",n);
            break;
            
            case 10:
            sort();
            break;
            
            case 11:
            search();
            break;
            
            case 12:
            display();
            break;
            
            
        }
    }while(option!=13);
    
    return 0;
}

void cr()
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    start=newnode;
    newnode->next=NULL;
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
    }
    else
    {
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        
        newnode->next=start;
        start=newnode;
    }
}

void add_aft()
{
    printf("Enter no\n");
    scanf("%d",&e);

    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    
    ptr=start;
    while(ptr->data!=e)
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void add_bef()
{
    printf("Enter no\n");
    scanf("%d",&e);
    
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    
    ptr=start;
    while(ptr->data!=e)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    newnode->next=ptr;
    preptr->next=newnode;
}

void add_end()
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);

    ptr=start;
    while(ptr!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=NULL;
}

void del()
{
    if(start==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
    printf("Enter no\n");
    scanf("%d",&e);
    
    ptr=start;
    while(ptr->data!=e)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==start)
    {
        start=ptr->next;
        free(ptr);
    }
    else
    {
    preptr->next=ptr->next;
    free(ptr);
    }
    }
}

int del_aft()
{
    if(start==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
    printf("Enter no\n");
    scanf("%d",&e);
    
    ptr=start;
    while(ptr->data!=e)
    {
        ptr=ptr->next;
        postptr=ptr->next;
        if(postptr==NULL)
        {
            printf("No node after given element");
            return 1;
        }
    }
    ptr->next=postptr->next;
    free(postptr);
    }
    return 0;
}

int del_bef()
{
    if(start==NULL)
    {
        printf("Underflow");
    }
    else
    {
    printf("Enter no\n");
    scanf("%d",&e);
    
    ptr=start;
    while(ptr->next->data!=e)
    {
        preptr=ptr;
        ptr=ptr->next;
        if(ptr->next==NULL)
        {
            printf("Element not there\n");
            return 1;
        }
    }
    preptr->next=ptr->next;
    free(ptr);
    }
    return 0;
}

int nodes()
{
    int counter=0;
    ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        counter++;
    }
    return counter;
}

void sort()
{
    int n;
    n=nodes();
    if(n<2)
    {
        printf("Elements should be more than 2\n");
    }
    else
    {
        int temp,i,j;
        for(i=0;i<n;i++)
        {
            ptr=start;
            for(j=0;j<n-i-1;j++)
            {
                preptr=ptr;
                ptr=ptr->next;
                if(preptr->data>ptr->data)
                {
                    temp=preptr->data;
                    preptr->data=ptr->data;
                    ptr->data=temp;
                }
            }
        }
    }
}

void search()
{
    if(start==NULL)
    {
        printf("Underflow");
    }
    else
    {
        int location=0;
        printf("Enter element to be searched\n");
        scanf("%d",&e);
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->data==e)
            {
                printf("Element %d found at location %d \n",e,location+1);
                break;
            }
            location++;
            ptr=ptr->next;
        }
    }
}

void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
