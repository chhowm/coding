#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*생각주머니
* 흠흠..
* 맨 위 카드를 맨 아래로.. 어케 집어넣을까
* 큐...로?
* 카드는 맨위가 1부터 아래로 쌓여있지만
* 구현할 때는 맨아래를 1로 놓고 그 위로 쌓는다면?
* 그럼 큐구조로 가능
* 1이빠지고, 2도빠진 후에 2가 다시 push되는 구조로?
* 구글의 힘을 빌려 큐, 원형큐를 구현할 수 있었다.
*/

#define SIZE 1500

typedef struct
{
	int data[SIZE];
	int rear, front;
}queueType;

void InitQueue(queueType* Q)
{
	Q->rear = Q->front = 0;
}
// 큐가 비었는지 꽉차있는지 확인하는 함수, 큐에 데이터 집어넣고 빼는 함수 필요
//큐가 꽉찼는지 확인하는 함수. 꽉찼으면 1반환
int QueueIsFull(queueType Q)
{
	return (Q.rear + 1) % SIZE == Q.front;
}
//큐가 비었는지 확인하는 함수. 비었으면 1반환
int QueueIsEmpty(queueType Q)
{
	return Q.rear == Q.front;
}
//큐에 데이터 집어넣는 함수 // 성공시 1반환 실패시 -1반환
int EnQueue(queueType* Q, int enNum)
{
	// 버그 생길 수도 있는 부분. 문제 있으면 여기 확인해보자
	if (QueueIsFull(*Q))
	{
		return -1;
	}
	else
	{
		Q->rear = (Q->rear + 1) % SIZE;
		Q->data[Q->rear] = enNum;
		return 1;
	}
}
//큐 데이터 삭제하는 함수 // 성공시 삭제하는(pop)데이터 반환, 실패시 -1반환
int DeQueue(queueType* Q)
{
	if (QueueIsEmpty(*Q))
	{
		return -1;
	}
	//만약 반환하는 데이터가 -1일경우 실패와 리턴값이 같아 문제가 생길 수 있다.
	//일단 지금 문제에서는 해당하는 경우가 없긴함
	//추후 생각해보자.
	else
	{
		Q->front = (Q->front+1)%SIZE;
		return Q->data[Q->front];
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	queueType card;
	InitQueue(&card);
	for (int i = 1; i <= n; i++)
	{
		if (!EnQueue(&card, i)) 
		{
			printf("queue is full\n");
			return 0;
		}
	}

	for (;;)
	{
		int ret = DeQueue(&card);
		if (QueueIsEmpty(card))
		{
			printf("%d\n", ret);
			break;
		}
		printf("%d ", ret);
		
		ret = DeQueue(&card);
		EnQueue(&card, ret);
	}
	//printf("%d\n", DeQueue(&card));
	return 0;
}