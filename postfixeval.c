#include <stdio.h>
#include <ctype.h>
#define size 10
char postfix[20];
int stack[20],top=-1;
void push(char b);
char pop();
void postfix_eval();

void main()
{
    printf("enter postfix expression:\n");
    scanf("%s", postfix);
    printf("postfix %s", postfix);

    postfix_eval();
}

void postfix_eval()
{
int i=0,op1,op2,res;
char symbol;
while((symbol=postfix[i++])!='\0')
{
if(isdigit(symbol))
push(symbol-'0');
else
{
op2=pop();
op1=pop();
switch(symbol)
{
case '+':
res=op1+op2;
        push(res);
        break;
case '-':res=op1-op2;
        push(res);
        break;
case '*':res=op1*op2;
        push(res);
        break;
case '/':res=op1/op2;
        push(res);
        break;
}
}
}
printf("result is %d",pop());

}
void push(char b){
    if(top==size-1)
    {
        return;
    }
    stack[++top] = b;
}

char pop(){
    char val = stack[top];
    top--;
    return(val);
}
