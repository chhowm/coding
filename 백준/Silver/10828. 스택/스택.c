#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define COMMAND_SIZE 6

void Pop(int *st, int *top)
{
	if (*top > 0)
	{
		(*top)--;
		printf("%d\n", st[*top]);
	}
	else
	{
		printf("-1\n");
	}
}

void Push(int* st, int* top, int num)
{
	if (*top < STACK_SIZE)
	{
		st[*top] = num;
		(*top)++;
	}
}

void StackCommand()
{
	int top = 0;
	int inputNum;
	//int stack[STACK_SIZE] = { 0 };
	char inputWord[COMMAND_SIZE] = { 0 };
	int commandNum;
	scanf("%d", &commandNum);

	int* stack = malloc(sizeof(int) * commandNum);
	for (int i = 0; i < commandNum; i++)
	{
		scanf("%s", inputWord);

		if (strcmp(inputWord, "push") == 0)
		{
			scanf(" %d", &inputNum);
			Push(stack, &top, inputNum);
		}
		else if (strcmp(inputWord, "pop") == 0)
		{
			Pop(stack, &top);
		}
		else if (strcmp(inputWord, "size") == 0)
		{
			printf("%d\n", top);
		}
		else if (strcmp(inputWord, "empty") == 0)
		{
			if (top == 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(inputWord, "top") == 0)
		{
			if (top == 0) printf("-1\n");
			else
			{
				printf("%d\n", stack[top - 1]);
			}
		}
	}
}

int main()
{
	StackCommand();
	return 0;
}