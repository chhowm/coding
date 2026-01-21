#include <stdio.h>
#include <stdlib.h>

int front=0, rear=0;

void EnQueue(int *Q, int card, int len)
{
    Q[rear] = card;
    rear = (rear + 1) % len;
}

int DeQueue(int *Q, int len)
{
    int deQueueNum = Q[front];
    front = (front + 1) % len;
    return deQueueNum;
}

int main()
{
    int N;
    scanf("%d", &N);
    int cardQueueMax = N+2;
    int* cardQueue = malloc(sizeof(int) * cardQueueMax);

    for(int i=0; i < N; i++)
    {
        EnQueue(cardQueue, i+1, cardQueueMax);
    }

    while((rear - front + cardQueueMax) % cardQueueMax > 1)
    {
        DeQueue(cardQueue, cardQueueMax);
        EnQueue(cardQueue, DeQueue(cardQueue, cardQueueMax), cardQueueMax);
    }

    printf("%d\n", cardQueue[front]);

    free(cardQueue);

    return 0;
}