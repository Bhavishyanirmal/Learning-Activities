#include <stdio.h>

void tower(int n, char source, char auxiliary, char destination)
{
    if(n == 0)
    {
        return;
    }

    tower(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    tower(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');

    return 0;
}