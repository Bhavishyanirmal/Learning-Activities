#include <stdio.h>

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int modulus(int a, int b);

int main()
{
    int choice, a, b;

    while (1)
    {
        printf("\n===== MENU =====");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Modulus");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 6)
        {
            printf("Program terminated.");
            break;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        switch (choice)
        {
            case 1:
                printf("Result = %d", addition(a, b));
                break;

            case 2:
                printf("Result = %d", subtraction(a, b));
                break;

            case 3:
                printf("Result = %d", multiplication(a, b));
                break;

            case 4:
                if (b != 0)
                    printf("Result = %d", division(a, b));
                else
                    printf("Division by zero is not allowed.");
                break;

            case 5:
                if (b != 0)
                    printf("Result = %d", modulus(a, b));
                else
                    printf("Modulus by zero is not allowed.");
                break;

            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}


int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

int modulus(int a, int b)
{
    return a % b;
}