#include <stdio.h>
#define MAX 5
int queue[MAX];
int f = -1;
int r = -1;
void enqueue()
{
    int value;
    if ((r + 1) % MAX == f)
    {
        printf("\nQueue is FULL\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    if (f == -1)
    {
        f = r= 0;
        
    }
    else
    {
        r = (r + 1) % MAX;
    }

    queue[r] = value;

    printf("%d inserted successfully.\n", value);
}

void dequeue()
{
    int value;

    if (f == -1)
    {
        printf("\nQueue is EMPTY\n");
        return;
    }

    value = queue[f];

    if (f == r)
    {
        f = r=-1;
    }
    else
    {
        f = (f + 1) % MAX;
    }

    printf("%d deleted successfully.\n", value);
}

void display()
{
    int i;
    if (f == -1)
    {
        printf("\nQueue is EMPTY\n");
        return;
    }

    printf("\nCircular Queue: ");
    i = f;
    while (1)
    {
        printf("%d ", queue[i]);

        if (i == r)
        {
            break;
        }
        i = (i + 1)%MAX;
    }

    printf("\n");
}
int main()
{
    int choice;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram ended\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}