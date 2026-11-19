
#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    char branch[20];
    float marks;
};

int main()
{
    struct Student s[50];
    int n = 0, choice, roll, i, pos;

    while (1)
    {
        printf("\n1. Add Record");
        printf("\n2. Update Record");
        printf("\n3. Search by Roll Number");
        printf("\n4. Delete Record");
        printf("\n5. Display All");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Roll No: ");
            scanf("%d", &s[n].roll);
            printf("Name: ");
            scanf(" %[^\n]", s[n].name);
            printf("Branch: ");
            scanf(" %[^\n]", s[n].branch);
            printf("Marks: ");
            scanf("%f", &s[n].marks);
            n++;
        }

        else if (choice == 2)
        {
            printf("Enter Roll No: ");
            scanf("%d", &roll);

            for (i = 0; i < n; i++)
                if (s[i].roll == roll)
                {
                    printf("New Name: ");
                    scanf(" %[^\n]", s[i].name);
                    printf("New Branch: ");
                    scanf(" %[^\n]", s[i].branch);
                    printf("New Marks: ");
                    scanf("%f", &s[i].marks);
                    break;
                }

            if (i == n)
                printf("Record not found.");
        }

        else if (choice == 3)
        {
            printf("Enter Roll No: ");
            scanf("%d", &roll);

            for (i = 0; i < n; i++)
                if (s[i].roll == roll)
                {
                    printf("\nRoll: %d\nName: %s\nBranch: %s\nMarks: %.2f\n",
                           s[i].roll, s[i].name, s[i].branch, s[i].marks);
                    break;
                }

            if (i == n)
                printf("Record not found.");
        }

        else if (choice == 4)
        {
            printf("Enter Roll No: ");
            scanf("%d", &roll);

            for (i = 0; i < n; i++)
                if (s[i].roll == roll)
                {
                    pos = i;
                    for (i = pos; i < n - 1; i++)
                        s[i] = s[i + 1];

                    n--;
                    printf("Record deleted.");
                    break;
                }
        }

        else if (choice == 5)
        {
            for (i = 0; i < n; i++)
                printf("\n%d  %s  %s  %.2f",
                       s[i].roll, s[i].name,
                       s[i].branch, s[i].marks);
        }

        else if (choice == 6)
            break;

        else
            printf("Invalid choice.");
    }

    return 0;
}
