#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Structure for a node */
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


/*==================================================
  Function: newNode()
==================================================*/
struct node *newNode()
{
    struct node *p;

    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("\nMemory allocation failed!");
        return NULL;
    }

    printf("\nEnter value: ");
    scanf("%d", &p->data);

    p->next = NULL;

    return p;
}


/*==================================================
  Insert at First
==================================================*/
void insertFirst()
{
    struct node *p;

    p = newNode();

    if (p == NULL)
        return;

    p->next = head;
    head = p;

    printf("\nNode inserted at first.");
}


/*==================================================
  Insert at Last
==================================================*/
void insertLast()
{
    struct node *p, *temp;

    p = newNode();

    if (p == NULL)
        return;

    /* Empty list */
    if (head == NULL)
    {
        head = p;
        printf("\nNode inserted at last.");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;

    printf("\nNode inserted at last.");
}


/*==================================================
  Insert in Ordered List
  Ascending order
==================================================*/
void insertOrdered()
{
    struct node *p, *temp, *prev;

    p = newNode();

    if (p == NULL)
        return;

    /* Empty list or first position */
    if (head == NULL || p->data <= head->data)
    {
        p->next = head;
        head = p;

        printf("\nNode inserted in ordered list.");
        return;
    }

    temp = head;

    while (temp != NULL && temp->data < p->data)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = p;
    p->next = temp;

    printf("\nNode inserted in ordered list.");
}


/*==================================================
  Delete from First
==================================================*/
void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = head;
    head = head->next;

    printf("\nDeleted value = %d", temp->data);

    free(temp);
}


/*==================================================
  Delete from Last
==================================================*/
void deleteLast()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    /* Only one node */
    if (head->next == NULL)
    {
        printf("\nDeleted value = %d", head->data);

        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("\nDeleted value = %d", temp->data);

    free(temp);
}


/*==================================================
  Delete Specified Value
==================================================*/
void deleteValue()
{
    struct node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &value);

    /* First node */
    if (head->data == value)
    {
        temp = head;
        head = head->next;

        printf("\nDeleted value = %d", temp->data);

        free(temp);
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    /* Value not found */
    if (temp == NULL)
    {
        printf("\nValue not found!");
        return;
    }

    prev->next = temp->next;

    printf("\nDeleted value = %d", temp->data);

    free(temp);
}


/*==================================================
  Search
==================================================*/
void search()
{
    struct node *temp;
    int value;
    int position = 1;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nEnter value to search: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("\nValue found at position %d", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("\nValue not found!");
}


/*==================================================
  Display
==================================================*/
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = head;

    printf("\nList: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


/*==================================================
  Main Function
==================================================*/
void main()
{
    int choice;


    do
    {
        printf("\n\n1. Insert at First");
        printf("\n2. Insert at Last");
        printf("\n3. Insert in Ordered List");
        printf("\n4. Delete from First");
        printf("\n5. Delete from Last");
        printf("\n6. Delete Specified Value");
        printf("\n7. Search");
        printf("\n8. Display");
        printf("\n9. Exit");

        printf("\n======================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                insertFirst();
                display();
                break;

            case 2:
                insertLast();
                display();
                break;

            case 3:
                insertOrdered();
                display();
                break;

            case 4:
                deleteFirst();
                display();
                break;

            case 5:
                deleteLast();
                display();
                break;

            case 6:
                deleteValue();
                display();
                break;

            case 7:
                search();
                break;

            case 8:
                display();
                break;

            case 9:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 9);

}