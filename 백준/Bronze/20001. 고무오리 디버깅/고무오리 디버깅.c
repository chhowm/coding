#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int top = 0;

	while (1)
	{
		char temp[33];
		fgets(temp, 33, stdin);
		temp[strcspn(temp, "\n")] = '\0';

		if (strcmp(temp, "문제") == 0) top++;
		else if (strcmp(temp, "고무오리") == 0)
		{
			if (top > 0) top--;
			else top += 2;
		}
		else if (strcmp(temp, "고무오리 디버깅 끝") == 0) break;
	}
	
	if (top == 0) printf("고무오리야 사랑해\n");
	else printf("힝구\n");
	return 0;
}