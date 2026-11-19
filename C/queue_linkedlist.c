#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;


/* Enqueue */
void enqueue(int value)
{
    struct Node *p;

    p = (struct Node *)malloc(sizeof(struct Node));

    p->data = value;
    p->next = NULL;

    if(front == NULL)
    {
        front = rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }

    printf("%d inserted into queue\n", value);
}


/* Dequeue */
void dequeue()
{
    struct Node *p;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    p = front;

    printf("%d deleted from queue\n", front->data);

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }

    free(p);
}


/* Peek */
void peek()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element = %d\n", front->data);
}


/* Display */
void display()
{
    struct Node *p;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    p = front;

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}


/* Main */
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}