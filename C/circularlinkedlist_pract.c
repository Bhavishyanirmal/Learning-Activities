#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;


/* Insert First */

void insertFirst(int value)
{
    struct Node *p;

    p = (struct Node *)malloc(sizeof(struct Node));

    p->data = value;

    if(head==NULL )
    {
        head =p; 
        last =p;

        last->next =head; 
    }
    else
    {
        p->next = head;
        head = p;
        last->next =head; 
    }
}


/* Insert Last */

void insertLast(int value)
{
    struct Node *p;

    p = (struct Node *)malloc(sizeof(struct Node));

    p->data =  value;

    if(head==NULL)
    {
       head=last=p;
    }
    else
    {
        last->next =p; 
        p->next = head;
        last = p;
    }
}


/* Insert Ordered */

void insertOrdered(int value)
{
    struct Node *p, *temp, *prev;

    p = (struct Node *)malloc(sizeof(struct Node));

    p->data = value;

    if(head==NULL)
    {
        head = p;
        last = p;

        last->next = head;
    }
    else if(value<=head->data)
    {
        p->next = head;
        head = p;
        last->next =head; 
    }
    else if(value>head->data)
    {
        last->next = p;
        p->next = head;
        last = p;
    }
    else
    {
        temp = head;

        while(temp->next!=NULL && value>temp->data)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = p;
        p->next = temp;
    }
}


/* Display */

void display()
{
    struct Node *temp;

    if(head==NULL)
    {
        printf("\nList is Empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ",temp->data);

        temp = temp->next;
    }
    while(temp->next!= head);

    printf("\n");
}


/* Main */

int main()
{
    int choice, value;

    do
    {
        printf("\n--- Circular Linked List ---");
        printf("\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert Ordered");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter Choice: ");
        scanf("%d",choice);

        switch(choice)
        {
            case 1:

                printf("Enter Value: ");
                scanf("%d",&value);
                insertFirst(value);
                

                break;

            case 2:

                printf("Enter Value: ");
                scanf("%d",&value);
                insertLast(value);
                

                break;

            case 3:

                printf("Enter Value: ");
                scanf("%d",&value);
                insertOrdered(value);

                

                break;

            case 4:
                printf("Enter Value: ");
                scanf("%d",&value);

                

                break;

            case 5:

                printf("Program Ended\n");

                break;

            default:

                printf("Invalid Choice\n");
        }

    } while(choice!=5);

    return 0;
}