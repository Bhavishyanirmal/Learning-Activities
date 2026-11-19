#include <stdio.h>

int main()
{
    char str[100];
    char stack[100];
    int i=0;
    int top=0;
    int flag=1;

    printf("enter the string:");
    scanf("%s",str);

    stack[top]='$';
    while(str[i]!='c' && str[i]!='\0')  
    {
        top++;
        stack[top]=str[i];
        i++;
    }
    i++;
    while(str[i] !='\0')
    {
        if(stack[top]==str[i])
        {
            top--;
            i++;
        }
        else{
            flag=0;
            break;
        }        
    }
    if(stack[top]!='$')
    {
        flag=0;
    }
    if(flag)
    {
        printf("valid string");
    }
    else{
        printf("invalid string");

    }
    return 0;
}
