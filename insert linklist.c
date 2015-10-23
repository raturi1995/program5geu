#include<stdio.h>
#include<conio.h>
typedef struct node
{
    int info;
    struct node *next;
}node_type;
void insert(node_type**,node_type**);
void del(node_type **);
void display(node_type *);
void main()
{
    node_type *left=NULL,*right=NULL;
    int ch;
    do
    {
        printf("\n menu");
        printf("\n 1 for insert \n 2 for delete \n 3 for display \n 4 for exit");
        printf("\n enter the choice.");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert(&left,&right);
                break;
            case 2:
                if(left!=NULL)
                    del(&left);
                else
                    printf("\n Linked list  is empty");
                break;
            case 3:
                if(left==NULL)
                    printf("\n linked list is empty");
                else
                    display(left);
                break;
            case 4:
                break;
            default :
                printf("\n invalid choice");
        }
    }while(ch!=4);
}
void insert(node_type **l,node_type **r)
{
    node_type *p=(node_type*)malloc(sizeof(node_type));
    if(p!=NULL)
    {
        printf("\n enter the information ");
        scanf("%d",&p->info);
        if(*l==NULL)
        {
            *l=*r=p;
        }
        else
        {
            (*r)->next=p;
            *r=p;
        }
        (*r)->next=NULL;
    }
    else
    printf("\n node cannot be created");
}
void del(node_type **f)
{
    printf("\n the node deleted : %d",(*f)->info);
    *f=(*f)->next;
}
void display(node_type *f)
{
    printf("\n elements : ");
    do
    {
        printf("\n %d",f->info);
        f=f->next;
    }while(f!=NULL);
}

