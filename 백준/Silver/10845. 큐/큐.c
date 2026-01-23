#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int front=0, rear=0;

void CmdPush(int *Q, int len)
{
    int temp;
    scanf("%d", &temp);
    Q[rear] = temp;
    rear = (rear + 1) % len;
}

void CmdPop(int *Q, int len)
{
    if(rear == front)
    {
        printf("-1\n");
        return;
    }
    int deQueueNum = Q[front];
    front = (front + 1) % len;
    printf("%d\n", deQueueNum);
}

void CmdSize(int QueueMax)
{
    printf("%d\n", (rear-front+QueueMax)%QueueMax);
}

void CmdEmpty()
{
    if(front == rear)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

void CmdFront(int *Q)
{
    if(front == rear)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", Q[front]);
    }
}

void CmdBack(int *Q)
{
    if(front == rear)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", Q[rear-1]);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int QueueMax = N+1;
    int* Queue = malloc(sizeof(int) * QueueMax);
    char cmd[6] = {0};

    for(int i=0; i < N; i++)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "push")==0)
        {
            CmdPush(Queue, QueueMax);
        }
        else if(strcmp(cmd, "pop")==0)
        {
            CmdPop(Queue, QueueMax);
        }
        else if(strcmp(cmd, "size")==0)
        {
            CmdSize(QueueMax);
        }
        else if(strcmp(cmd, "empty")==0)
        {
            CmdEmpty();
        }
        else if(strcmp(cmd, "front")==0)
        {
            CmdFront(Queue);
        }
        else if(strcmp(cmd, "back")==0)
        {
            CmdBack(Queue);
        }
    }

    free(Queue);

    return 0;
}