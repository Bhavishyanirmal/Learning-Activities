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
  Purpose : Create a new node and return its address
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

    p->next=head;
    head=p;
    

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

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;


    printf("\nNode inserted at last.");
}


/*==================================================
  Insert in Ordered List
  List is maintained in ascending order
==================================================*/
void insertOrdered()
{
    struct node *p, *temp,*prev;

    p = newNode();

    if (p == NULL)
        return;

    temp=head;
   
    if(head->next==NULL&& head->data>p->data )
    {
        p->next=head;
        head=p;
    }
    
    while(temp->data>p->data)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=p;
    p->next=temp;
    printf("\nNode inserted in ordered list.");
}


/*==================================================
  Delete from First
==================================================*/
void deleteFirst()
{
    struct node *temp;
    temp=head;

    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
       head=head->next;
         
       
       

    }

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


}


/*==================================================
  Main Function
==================================================*/
void main()
{
    int choice;
    do
    {

	printf("\n1. Insert at First");
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
		display();
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