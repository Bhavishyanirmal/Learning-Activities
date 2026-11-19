

#include <stdio.h>

int main()
{
    char s[10];
    char r[10];
    int count = 0;

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    int j = 0;

    for(int i = count - 1; i >= 0; i--)
    {
        r[j] = s[i];
        j++;
    }

    r[j] = '\0';

    printf("Reverse string: %s", r);

    return 0;
}