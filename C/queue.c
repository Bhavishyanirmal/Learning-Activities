// #include <stdio.h>

// #define MAX 10

// int queue[MAX];
// int f = -1;
// int r = -1;

// // Function to Insert (Enqueue)
// void enqueue()
// {

// }

// // Function to Delete (Dequeue)
// void dequeue()
// {

// }

// // Function to Display Queue
// void display()
// {

// }

// // Function to Peep
// void peep()
// {

// }

// // Function to Update
// void update()
// {

// }

// // Main Function
// int main()
// {
//     int choice;

//     do
//     {
//         printf("\n1. Insert (Enqueue)");
//         printf("\n2. Delete (Dequeue)");
//         printf("\n3. Peep");
//         printf("\n4. Update");
//         printf("\n5. Display");
//         printf("\n6. Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1:
//                 enqueue();
//                 break;

//             case 2:
//                 dequeue();
//                 break;

//             case 3:
//                 peep();
//                 break;

//             case 4:
//                 update();
//                 break;

//             case 5:
//                 display();
//                 break;

//             case 6:
//                 printf("\nProgram Terminated.\n");
//                 break;

//             default:
//                 printf("\nInvalid Choice! Please try again.\n");
//         }

//     } while(choice != 6);

//     return 0;
// }




#include <stdio.h>
#define MAX 10
int queue[MAX];
int f = -1;
int r = -1;
void enqueue()
{
    int value;
    if (r == MAX - 1)
    {
        printf("\nQueue Overflow!");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);

    if (f == -1)
    {
        f = 0;
    }
    r++;
    queue[r] = value;

    printf("Inserted Successfully.");
}

void dequeue()
{
    if (f == -1 || f > r)
    {
        printf("\nQueue Underflow!");
        return;
    }

    printf("Deleted Element = %d", queue[f]);

    f++;

    if (f == r)
    {
        f = r = -1;
    }
}

void display()
{
    int i;

    if (f == -1)
    {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nQueue Elements: ");

    for (i = f; i <= r; i++)
    {
        printf("%d ", queue[i]);
    }
}

void peep()
{
    if (f == -1)
    {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nf Element = %d", queue[f]);
}

void update()
{
    int pos, value;

    if (f == -1)
    {
        printf("\nQueue is Empty!");
        return;
    }

    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > (r - f + 1))
    {
        printf("\nInvalid Position!");
        return;
    }

    printf("Enter New Value: ");
    scanf("%d", &value);

    queue[f + pos - 1] = value;

    printf("Updated Successfully.");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peep");
        printf("\n4. Update");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue();
                     break;
            case 2: dequeue();  
                     break;
            case 3: peep();
                     break;
            case 4: update();
                     break;
            case 5: display();
                     break;
            case 6: printf("\nProgram Terminated.\n");
                     break;
            default: printf("\nInvalid Choice!");
        }

    } while(choice != 6);

    return 0;
}