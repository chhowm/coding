#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRING_MAX_SIZE 50

void StackPush(char *st, char c, int *top)
{
	st[*top] = c;
	(*top)++;
}

void StackPop(char* st, int* top)
{
	(*top)--;
}

void CommandExecute()
{
	char inputString[STRING_MAX_SIZE];
	scanf("%s", inputString);

	int top = 0;
	int cnt = 0;
	int len = strlen(inputString);
	int stackSize = len;
	char *stack = malloc(sizeof(char) * stackSize);

	for (int i = 0; i < len; i++)
	{
		if (inputString[i] == '(')
		{
			StackPush(stack, inputString[i], &top);
		}
		else if (inputString[i] == ')')
		{
			if (stack[top - 1] == '(') StackPop(stack, &top);
			else cnt++;
		}
	}
	printf("%d\n", top + cnt);
}

int main()
{
	CommandExecute();
	return 0;
}