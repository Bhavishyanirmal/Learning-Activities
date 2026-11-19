#include <stdio.h>

struct Student
{
    int rollNo;
    char branch[30];
    float totalMarks;
};

int main()
{
    struct Student s[100], temp;
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student records
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Branch: ");
        scanf(" %[^\n]", s[i].branch);

        printf("Total Marks: ");
        scanf("%f", &s[i].totalMarks);
    }

    // Sort records based on total marks
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].totalMarks < s[j].totalMarks)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display sorted records
    printf("\n===== STUDENT RECORDS =====\n");
    printf("Roll No.\tBranch\t\tTotal Marks\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               s[i].rollNo,
               s[i].branch,
               s[i].totalMarks);
    }

    return 0;
}