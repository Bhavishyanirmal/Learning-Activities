#include <stdio.h>
#include <stdlib.h>

int findSum(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int findLargest(int arr[], int n)
{
    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

int findSmallest(int arr[], int n)
{
    int smallest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest;
}

float findAverage(int sum, int n)
{
    return (float)sum / n;
}

int main()
{
    int *arr;
    int n, sum;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("num%d:", i+1);
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    sum = findSum(arr, n);

    printf("\nSum = %d", sum);
    printf("\nLargest = %d", findLargest(arr, n));
    printf("\nSmallest = %d", findSmallest(arr, n));
    printf("\nAverage = %.2f\n", findAverage(sum, n));

    free(arr);

    return 0;
}
