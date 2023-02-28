#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*tail= NULL;
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
    newnode->link=NULL;
  if(tail==NULL)
    {
        tail=newnode;
        return;
    }
  else
    {
      newnode->link=tail->link;
       tail->link=newnode;
    }
}
void insert_end()
{
      struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    if(tail==NULL)
    {
       tail=newnode;
       return;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
        return;
    }
}
void delete_front()
{
    struct node *temp;
    if(tail=NULL)
    {
        printf("the list is empty");
    }
    else
    {
        temp=tail->link;
        tail->link=temp->link;
        free(temp);
        temp=NULL;
    }
}
void delete_end()
{
     struct node *temp;
     if(tail==NULL)
    {
        printf("the list is empty");
        return;
    }
    else
    {
        temp=tail->link;
        while(temp->link!=tail)
        {
            temp=temp->link;
        }
        temp->link=tail->link;
        free(tail);
        tail=temp;
    }
}
void display()
{
    struct node *temp;
    if(tail==NULL)
    {
     printf("empty list");
     return;
    }
    else
    {
      temp=tail->link;
    }
    do{
    printf("%d-->",temp->data);
      temp=temp->link;
    }while(temp!=tail->link);
}



