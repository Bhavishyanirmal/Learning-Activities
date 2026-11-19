#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int n)
{
    int *start = arr;
    int *end = arr + n - 1;

    while (start < end)
    {
        swap(start, end);
        start++;
        end--;
    }
}

int largest(int *arr, int n)
{
    int max = *arr;

    for (int *p = arr + 1; p < arr + n; p++)
        if (*p > max)
            max = *p;

    return max;
}

int main()
{
    int a, b, n, arr[50];

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    swap(&a, &b);
    printf("After swapping: %d %d\n", a, b);

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int *p = arr; p < arr + n; p++)
        scanf("%d", p);

    reverse(arr, n);

    printf("Reversed array: ");
    for (int *p = arr; p < arr + n; p++)
        printf("%d ", *p);

    printf("\nLargest = %d", largest(arr, n));

    return 0;
}