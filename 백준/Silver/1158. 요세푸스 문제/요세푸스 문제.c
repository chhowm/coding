#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
        
    int front = 0, rear = 0, j=1, cnt = 1;
    int *queue = malloc(sizeof(int) * N);
    for(int i=1; i<=N; i++)
    {
        queue[rear++]= i;
    }

    printf("<");
    while(rear - front != 1)
    {
        for(int i=1; i <= K; i++)
        {
            if(i == K)
            {
                printf("%d, ", queue[front]);
                front = (front+1) % N;
            }
            else
            {
                queue[rear] = queue[front];
                rear = (rear+1) % N;
                front = (front+1) % N;
            }
        }
    }
    printf("%d", queue[front]);
    printf(">\n");
    
    return 0;
}