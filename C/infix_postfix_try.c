#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// PUSH
void push(char ch)
{
    // write push logic
    stack[++top]= ch;
}

// POP
char pop()
{
    return stack[top--];
}

// PRIORITY
int priority(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/' || ch=='%')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    // ^ → 3
    // * / → 2
    // + - → 1
    // otherwise → 0
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix: ");
    scanf("%s", infix);

    // Read expression character by character
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // 1. If alphabet/number
        if (isalnum(ch))
        {
            // put ch in postfix
            postfix[i]= ch;
        }

        // 2. If '('
        else if (ch == '(')
        {
            // push ch
            stack[i++]=ch;
        }

        // 3. If ')'
        else if (ch == ')')
        {
            while ( stack[top]!='(')
            {
                pop();
            }
            
        }

        // 4. If operator
        else
        {
            // pop higher/equal priority operators
            // then push current operator
           while()
           {
            
           }
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        // put pop() into postfix
    }

    // End postfix string
    postfix[j] = '\0';

    printf("Postfix: %s", postfix);

    return 0;
}