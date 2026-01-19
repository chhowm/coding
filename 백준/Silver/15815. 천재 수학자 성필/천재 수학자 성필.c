#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

void stackPush(int *st, int *top, int n)
{
    if(*top > MAX_SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    st[(*top)++] = n;
}

int stackPop(int *st, int *top)
{
    if(*top == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return st[--(*top)];
}

int main()
{
    char mathExpression[MAX_SIZE] ={0};
    scanf("%s", mathExpression);

    int stack[MAX_SIZE];
    int top = 0;
    int len = strlen(mathExpression);
    for(int i=0; i < len; i++)
    {
        if(mathExpression[i] >= '0' && mathExpression[i] <= '9')
        {
            stackPush(stack, &top, mathExpression[i]-'0');
        }
        else
        {
            int a = stackPop(stack, &top);
            int b = stackPop(stack, &top);
            if(mathExpression[i] == '+')
            {
                stackPush(stack, &top, b+a);
            }
            else if(mathExpression[i] == '-')
            {
                stackPush(stack, &top, b-a);
            }
            else if(mathExpression[i] == '*')
            {
                stackPush(stack, &top, b*a);
            }
            else if(mathExpression[i] == '/')
            {
                stackPush(stack, &top, b/a);
            }
        }
    }
    printf("%d\n",stack[top-1]);

    return 0;
}