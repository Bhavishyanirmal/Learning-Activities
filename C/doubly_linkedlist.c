#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;


/* Insert at End */
void insertEnd(int value)
{
    struct Node *p;

    p = (struct Node *)malloc(sizeof(struct Node));

    p->data = value;
    p->prev = NULL;
    p->next = NULL;

    if(head == NULL)
    {
        head = last = p;
    }
    else
    {
        p->prev = last;
        last->next = p;
        last = p;
    }
}


/* Delete node before specified position */
void deleteBefore(int pos)
{
    struct Node *p;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos <= 1)
    {
        printf("No node exists before position %d\n", pos);
        return;
    }

    p = head;

    for(int i = 1; i < pos - 1; i++)
    {
        if(p->next == NULL)
        {
            printf("Invalid position\n");
            return;
        }

        p = p->next;
    }

    if(p->prev == NULL)
    {
        printf("No node exists before position %d\n", pos);
        return;
    }

    if(p->prev->prev == NULL)
    {
        head = p;
        p->prev = NULL;
    }
    else
    {
        p->prev->prev->next = p;
        p->prev = p->prev->prev;
    }

    free(p->prev);
}


/* Display */
void display()
{
    struct Node *p;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    p = head;

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
    int choice, value, pos;

    while(1)
    {
        printf("\n1. Insert at End");
        printf("\n2. Delete Before Position");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteBefore(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}+