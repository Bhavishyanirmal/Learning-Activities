#include <stdio.h>

int main()
{
    int choice, a, b;

    while (1)
    {
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
            printf("Thank You!\n");
            return 0;
        }

        printf("Enter two numbers: ");
        scanf("%d%d", &a, &b);

        if (choice == 1)
            printf("Addition = %d\n", a + b);

        else if (choice == 2)
            printf("Subtraction = %d\n", a - b);

        else if (choice == 3)
            printf("Multiplication = %d\n", a * b);

        else if (choice == 4)
        {
            if (b != 0)
                printf("Division = %.2f\n", (float)a / b);
            else
                printf("Division by zero is not possible.\n");
        }

        else if (choice == 5)
        {
            if (b != 0)
                printf("Modulus = %d\n", a % b);
            else
                printf("Modulus by zero is not possible.\n");
        }

        else
            printf("Invalid Choice!\n");
    }

    return 0;
}