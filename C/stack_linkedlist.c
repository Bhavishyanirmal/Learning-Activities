
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push()
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully\n");
}

void pop()
{
    struct Node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display()
{
    struct Node *temp;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
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
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}
