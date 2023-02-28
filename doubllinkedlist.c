#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *nextlink, *prevlink;
}*head = NULL;
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();
void main()
{
 int ch;
  while(ch!=6)
    {
        printf("\nEnter the operation to be performed\n");
        printf("\n 1.insert_front\n 2.insert_end \n 3.delete_front\n 4.delete_end\n 5.Show\n 6.Exit\n");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:
                insert_front();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);

            default:
                printf("invalid option");
         }
    }
}
void insert_front()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->prevlink = NULL;
    newnode->nextlink = NULL;
    if(head==NULL)
        {
        head=newnode;
        return;
        }
    else
        {
            newnode->nextlink=head;
            head->prevlink=newnode;
            newnode->prevlink=NULL;
            head=newnode;
        }
}
void insert_end()
{
     struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->prevlink=NULL;
    newnode->nextlink=NULL;
    if(head==NULL)
    {
       head=newnode;
       return;
    }

    else
        {
            temp = head;
            while(temp->nextlink!=NULL)
            {
              temp=temp->nextlink;
            }
            temp->nextlink=newnode;
            newnode->prevlink=temp;
        }
}
void delete_front()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("the list is empty");
        return;
    }
    else
        {
            temp=head;
    head=head->nextlink;
        free(temp);
    head->prevlink=NULL;
    temp=NULL;
        }
}
void delete_end()
{
    struct node *temp,*temp1;
     if(head==NULL)
    {
        printf("the list is empty");
        return;
    }
    else
        {
            temp=head;
            while(temp->nextlink!=NULL)
            {
                temp=temp->nextlink;
            }
            temp1=temp->prevlink;
            free(temp);
            temp1->nextlink=NULL;
            temp=NULL;
        }
}
void display()
{
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
      count=count+1;
      printf("%d-->",temp->data);
      temp=temp->nextlink;
    }
}

