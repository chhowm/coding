#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front = 0, rear = 0;

int DeQueue(int *Q, int len)
{
    int ret = Q[front];
    front = (front+1) % len;
    return ret;
}

void EnQueue(int *Q, int n, int len)
{
    Q[rear] = n;
    rear = (rear+1)%len;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int queLen = N+1;
    int *people = malloc(sizeof(int) * (queLen));

    for(int i=1; i<=N; i++)
    {
        EnQueue(people, i,queLen);
    }

    printf("<");

    while(((rear-front+queLen)%(queLen)) != 1)
    {
        for(int i=0; i<K-1; i++)
        {
            EnQueue(people, DeQueue(people, queLen), queLen);
        }
        printf("%d, ", DeQueue(people, queLen));
    }
    printf("%d>",DeQueue(people, queLen));
    free(people);
    return 0;
}