// #include <stdio.h>

// #define MAX 5

// int stack[MAX];
// int top = -1;

// void push()
// {
    
// }

// // Function to Pop an element
// void pop()
// {
    
// }

// // Function to Display Stack
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
//         printf("\n1. Push");
//         printf("\n2. Pop");
//         printf("\n3. Peep");
//         printf("\n4. Update");
//         printf("\n5. Display");
//         printf("\n6. Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1:
//                 push();
//                 break;

//             case 2:
//                 pop();
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

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Inserted Successfully.");
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
        return;
    }

    printf("\nDeleted Element = %d", stack[top]);

    top--;
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }

    printf("\nStack Elements:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void peep()
{
    if (top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }

    printf("\nTop Element = %d", stack[top]);
}

void update()
{
    int pos, value;

    if (top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }

    printf("Enter Position from TOP: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > top + 1)
    {
        printf("\nInvalid Position!");
        return;
    }

    printf("Enter New Value: ");
    scanf("%d", &value);

    stack[top - pos + 1] = value;

    printf("Updated Successfully.");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peep");
        printf("\n4. Update");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: update(); break;
            case 5: display(); break;
            case 6: printf("\nProgram Terminated.\n"); break;
            default: printf("\nInvalid Choice!");
        }

    } while(choice != 6);

    return 0;
}