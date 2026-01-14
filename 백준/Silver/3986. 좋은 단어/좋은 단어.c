#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STACKSIZE 100000
bool StackPush(int* top_ptr, char* stack, char c)
{
	if (*top_ptr >= STACKSIZE)
	{
		return false;
	}
	stack[(*top_ptr)++] = c;
	return true;
}

void StackPop(int* top_ptr, char* stack)
{
	if (*top_ptr == 0)
	{
		printf("stack if empty\n");
		return;
	}
	(*top_ptr)--;
}

bool CheckGoodNum(char* w)
{
	int top = 0;
	int len = strlen(w);
	char ch[STACKSIZE] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (top > 0 && ch[top-1] == w[i])
		{
			StackPop(&top, ch);
		}
		else
		{
			if (!StackPush(&top, ch, w[i]))
			return false;
		}
	}
	if (top == 0) return true;
	else return false;
}

int main()
{
	int cnt = 0;
	char word[100000] = { 0 };
	int wordNum;
	scanf("%d", &wordNum);

	for (int i = 0; i < wordNum; i++)
	{
		scanf("%s", word);
		if (CheckGoodNum(word)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}