#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = NULL, n, choice;

    while (1)
    {
        printf("\n\n1. malloc()");
        printf("\n2. calloc()");
        printf("\n3. realloc()");
        printf("\n4. free()");
        printf("\n5. Display values");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter size: ");
            scanf("%d", &n);

            p = (int *)malloc(n * sizeof(int));

            if (p == NULL)
                printf("Memory allocation failed.");
            else
                printf("Memory allocated at address: %p", (void *)p);
        }

        else if (choice == 2)
        {
            printf("Enter size: ");
            scanf("%d", &n);

            p = (int *)calloc(n, sizeof(int));

            if (p == NULL)
                printf("Memory allocation failed.");
            else
                printf("Memory allocated at address: %p", (void *)p);
        }

        else if (choice == 3)
        {
            printf("Enter new size: ");
            scanf("%d", &n);

            p = (int *)realloc(p, n * sizeof(int));

            if (p == NULL)
                printf("Memory resizing failed.");
            else
                printf("Memory resized at address: %p", (void *)p);
        }

        else if (choice == 4)
        {
            free(p);
            p = NULL;

            printf("Memory freed.\n");
            printf("Current address: %p", (void *)p);
        }

        else if (choice == 5)
        {
            if (p == NULL)
            {
                printf("No memory allocated.");
            }
            else
            {
                printf("Enter number of values to display: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++)
                    printf("Address: %p  Value: %d\n",
                           (void *)(p + i), p[i]);
            }
        }

        else if (choice == 6)
        {
            free(p);
            break;
        }

        else
            printf("Invalid choice.");
    }

    return 0;
}