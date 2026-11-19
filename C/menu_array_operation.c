#include <stdio.h>

#define MAX 100

void insert(int arr[], int *n)
{
    int pos, value;

    if (*n >= MAX)
    {
        printf("Array is full.\n");
        return;
    }

    printf("Enter position (1 to %d): ", *n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    for (int i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *n)
{
    int pos;

    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    printf("Element deleted successfully.\n");
}

void search(int arr[], int n)
{
    int value, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found.\n");
}

void display(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void findMaxMin(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
}

int main()
{
    int arr[MAX], n, choice;

    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("\n===== ARRAY MENU =====");
        printf("\n1. Insert element");
        printf("\n2. Delete element");
        printf("\n3. Search element");
        printf("\n4. Display array");
        printf("\n5. Find maximum and minimum");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert(arr, &n);
                break;

            case 2:
                deleteElement(arr, &n);
                break;

            case 3:
                search(arr, n);
                break;

            case 4:
                display(arr, n);
                break;

            case 5:
                findMaxMin(arr, n);
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}