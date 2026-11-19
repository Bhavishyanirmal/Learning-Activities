#include <stdio.h>
#include<ctype.h>

#define max 100
int stack[max];
int top =-1;

void push(int value)
{
    stack[++top]=value;
}

int pop()
{
    return stack[top--];
}

int evaluation()
{
    int i=0;
    int a,b;

    int b=pop();
    int a=pop();

    if()
    {
        
    }
}
int main()
{

   char postfix[]="123+-*";
    return 0;
}