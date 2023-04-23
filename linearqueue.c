//Elementary Queue operations
#include<stdio.h>
#define size 10
void operatons();
void create();
void delete();
void display();
int q[size],rear=-1,front=0,option,data,ele;

void main()
{
    operations();
}

void operations()
{
    printf("\n");
    printf("Enter the number:\n");
    printf("1. Insert\n");
    printf("2. Remove\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1: insert();
        case 2: delete();
        case 3: display();
        case 4: exit(1);
        default: printf("Enter a valid expression!\n");
                operations();
    }
}

void insert()
{
    if(rear == size-1)
    {
        printf("Queue is full!\n");
        operations();
    }
    else
    {
        printf("Enter the element:\n");
        scanf("%d",&data);
        q[++rear] = data;
        operations();
    }
}

void delete()
{
    if(rear == front)
    {
        printf("Queue is empty!\n");
        operations();
    }
    else
    {
        ele = q[front];
        printf("Deleted element is %d\n",ele);
        front++;
        operations();
    }
}

void display()
{
    if(rear == front-1)
    {
        printf("Queue is empty!\n");
        operations();
    }
    else
    {
        printf("Elements of queue are:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d   ",q[i]);
        }
        printf("\n");
        operations();
    }
}
