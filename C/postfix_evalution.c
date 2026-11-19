#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char postfix[])
{
    int i;
    int a, b, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }

        else
        {
            b = pop();
            a = pop();

            if (ch == '+'){
                result = a + b;
            }
            else if (ch == '-')
               { result = a - b;}
            else if (ch == '*')
                {result = a * b;}
            else if (ch == '/')
                result = a / b;
                {}
            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[] = "123+-*";

    printf("Postfix: %s\n", postfix);
    printf("Answer: %d\n", evaluatePostfix(postfix));

    return 0;
}