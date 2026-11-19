#include <stdio.h>

int findLength(char str[])
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

void reverseString(char str[], char rev[])
{
    int len = findLength(str);

    for (int i = 0; i < len; i++)
        rev[i] = str[len - 1 - i];

    rev[len] = '\0';
}

int isPalindrome(char str[])
{
    int i = 0;
    int j = findLength(str) - 1;

    while (i < j)
    {
        if (str[i] != str[j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

int countVowels(char str[])
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U')
        {
            count++;
        }
    }

    return count;
}

int compareStrings(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];

        i++;
    }

    return str1[i] - str2[i];
}

void displayName(char name[])
{
    printf("Name = %s\n", name);
}

int main()
{
    char str[100], str2[100], rev[100];
    int choice;

    printf("Enter your name: ");
    scanf(" %[^\n]", str);

    printf("Enter another string for comparison: ");
    scanf(" %[^\n]", str2);

    while (1)
    {
        printf("\n===== STRING MENU =====");
        printf("\n1. Find Length");
        printf("\n2. Check Palindrome");
        printf("\n3. Reverse String");
        printf("\n4. Count Vowels");
        printf("\n5. Display Name");
        printf("\n6. Compare Two Strings");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Length = %d\n", findLength(str));
                break;

            case 2:
                if (isPalindrome(str))
                    printf("String is a Palindrome.\n");
                else
                    printf("String is not a Palindrome.\n");
                break;

            case 3:
                reverseString(str, rev);
                printf("Reversed String = %s\n", rev);
                break;

            case 4:
                printf("Number of vowels = %d\n", countVowels(str));
                break;

            case 5:
                displayName(str);
                break;

            case 6:
            {
                int result = compareStrings(str, str2);

                if (result == 0)
                    printf("Both strings are equal.\n");
                else if (result < 0)
                    printf("First string is smaller than second string.\n");
                else
                    printf("First string is greater than second string.\n");

                break;
            }

            case 7:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}