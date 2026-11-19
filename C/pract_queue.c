#include <stdio.h>
#define MAX 5
int queue[MAX];
int f=-1;
int r=-1;

void enqueue()
{
    int value;
    printf("Enter the value:");
    scanf("%d",value);

    if((r+1)% MAX==f)
    {
        printf("queue is full");
    }
    else if(f==-1)
    {
        f=r=0;
    }
    else
    {
        r=(r+1) % MAX;
    }
}


void dequeue()
{
   
    if(f==-1)
    {
        printf("queue is empty");
        return;
    }
    else if(f=r=0)
    {
        f=r=-1;
    }
    else
    {
       f=(f+1) % MAX;
    }
}


void display()
{
    
    int i=f;

    if(f==-1)
        {
            printf("queue is empty");
        }
    while(1)
    {
      printf(" queue values:%d",queue[i]);
      if(i==r)
      {
        break;
      }
      i=(i+1) % MAX;
    }
}


int main()
{
    int choice;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram ended\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}