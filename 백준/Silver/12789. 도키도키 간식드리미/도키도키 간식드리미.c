#include <stdio.h>
#include <stdlib.h>

int Pop(int *st, int *top)
{
    return st[(*top)--];
}

void Push(int *st, int *top, int n)
{
    st[(*top)++] = n;
}

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = 1;
    int top = 0;
    int *stack = malloc(sizeof(int) * n);
    int *numArray = malloc(sizeof(int) * n);
    for(int i =0; i<n; i++)
    {
        scanf("%d", &numArray[i]);

        if(numArray[i] != cnt)
        {
            Push(stack, &top, numArray[i]);
        }
        else if(numArray[i] == cnt)
        {
            cnt++;
        }
        for(;;)
        {
            if(top > 0 && stack[top-1] == cnt)
            {
                Pop(stack, &top);
                cnt++;
            }
            else break;
        }
    }

    if(top == 0) printf("Nice\n");
    else printf("Sad\n");

    free(stack);
    free(numArray);
    return 0;
}