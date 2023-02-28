#include<stdio.h>
#include<stdlib.h>
void operations();
void insert_front();
void insert_end();
void insert_pos();
void delete_front();
void delete_end();
void delete_pos();
void traverse();
int option,count=0,pos;
struct node
{
    int data;
    struct node *link;
}*head = NULL;
void main()
{
    printf("Single linked list\n");
    operations();
}

operations()
{
    printf("1. Insert at front\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete at front\n");
    printf("5. Delete at end\n");
    printf("6. Delete at position\n");
    printf("7. Display data\n");
    printf("8. Exit\n");
    printf("Choice:\t");
    scanf("%d",&option);
    switch(option)
    {
        case 1: insert_front();
                break;
        case 2: insert_end();
                break;
        case 3: insert_pos();
                break;
        case 4: delete_front();
                break;
        case 5: delete_end();
                break;
        case 6: delete_pos();
                break;
        case 7: traverse();
                break;
        case 8: exit(1);
        default: printf("Enter a valid choice!\n");
                operations();
    }
}

insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\t");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(head==NULL)
    {
        head = newnode;
        count++;
        operations();
    }
    else
    {
        newnode->link=head;
        head = newnode;
        count++;
        operations();
    }
}

insert_end()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\t");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(head == NULL)
    {
        head = newnode;
        count++;
        operations();
    }
    else
    {
        temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        count++;
        operations();
    }
}

insert_pos()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos>count+1)
    {
        printf("Enter the valid position!\n");
        operations();
    }
    else
    {
        printf("Enter the element:\t");
        scanf("%d",&newnode->data);
        temp = head;
        int move = 1;
        if(pos == 1)
        {
            newnode->link = head;
            head = newnode;
        }
        else if(count+1 == pos)
        {
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newnode;
        }
        else
        {
            while(move < pos)
            {
                temp = temp->link;
                move++;
            }
            newnode->link = temp->link;
            temp->link = newnode;
        }
        count++;
        operations();
    }
}

delete_pos()
{
    struct node *temp, *temp1;
    int pos;
    printf("Enter the position:\t");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("Enter the valid position!\n");
        operations();
    }
    else
    {
        temp = head;
        int move = 1;
        if(pos == 1)
        {
            temp = head;
            head = head->link;
            free(temp);
            temp = NULL;
        }
        else if(pos == count)
        {
            temp = head;
            while(temp->link != NULL)
            {
                temp1 = temp;
                temp = temp->link;
            }
            temp1->link = NULL;
            free(temp);
            temp = NULL;
        }
        else
        {
            while(move < pos)
            {
                temp1 = temp;
                temp = temp->link;
                move++;
            }
            temp1->link =temp->link;
            free(temp);
            temp = NULL;
        }
    }
    count--;
    operations();
}

delete_front()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty!\n");
        operations();
    }
    else
    {
        temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
        count--;
        operations();
    }
}

delete_end()
{
    struct node *temp, *temp1;
    if(head==NULL)
    {
        printf("List is empty!\n");
        operations();
    }
    else
    {
        temp = head;
        while(temp->link != NULL)
        {
            temp1 = temp;
            temp = temp->link;
        }
        temp1->link = NULL;
        free(temp);
        temp = NULL;
        count--;
        operations();
    }
}

traverse()
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("\nNo of elements: %d\n",count);
    printf("\n\n");
    operations();
}
