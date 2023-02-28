#include<stdio.h>
#include<stdlib.h>
int q[20],i,front=-1,rear=-1,ele,size=20;
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();
int main()
{
    while(1)
    {
        int opt;
        printf("enter opt: \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:insert_front();
                break;
            case 2:insert_rear();
                break;
            case 3:delete_front();
                break;
            case 4: delete_rear();
                break;
            case 5:display();
                break;
            default:
                exit(0);
        }
    }
}
void insert_front()
{
    if(front==0)
    printf("queue is full");
    else if(front==-1 && rear==-1){
        front=0,rear=0;
        printf("\nenter the element:");
        scanf("%d",&ele);
        q[front]=ele;
    }
    else{
        printf("\nenter the element: ");
        scanf("%d",&ele);
        q[--front]=ele;
    }

}
void insert_rear()
{
    if(rear==size-1)
    printf("\nstack is full");
    else if(front==-1 && rear==-1){
        front=0,rear=0;
        printf("enter the element:");
        scanf("%d",&ele);
        q[front]=ele;
    }
    else{
        printf("\n enter the element: ");
        scanf("%d",&ele);
        q[++rear]=ele;
    }
}
void delete_front()
{
    if(front==-1)
    printf("\nqueue is empty");
    else{
        // printf("\nenter the element: ");
        // scanf("%d",&ele);
        ele=q[front++];
        printf("\ndeleted element at front is %d\n",ele);
    }
}
void delete_rear()
{
    if(front==rear)
    printf("\n stack is empty");
    else{
        // printf("\n enter the element: ");
        // scanf("%d",&ele);
        ele=q[rear--];
        printf("\n deleted element at rear is %d",ele);
    }
}
void display()
{
    printf("\n elements is queue are:\n");
    for(int i=front;i<=rear;i++)
    printf("%d\n",q[i]);
}
