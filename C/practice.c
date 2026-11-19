#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int val;

    if(top == MAX - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &val);

        top++;
        stack[top] = val;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void pip()
{
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 0 || pos > top)
    {
        printf("Invalid position\n");
    }
    else
    {
        printf("Value is: %d\n", stack[pos]);
    }
}

void change()
{
    int pos, value;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 0 || pos > top)
    {
        printf("Invalid position\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        stack[pos] = value;
    }
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. PIP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                pip();
                break;

            case 4:
                change();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 6);

    return 0;
}