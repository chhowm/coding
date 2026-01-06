#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 51
int main()
{
	int N;
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		char string[25][MAX_LENGTH];
		int top = -1;

		char temp[MAX_LENGTH];
		fgets(temp, MAX_LENGTH, stdin);
		temp[strcspn(temp, "\n")] = '\0';

		char *ptr = strtok(temp, " ");
		while (ptr != NULL) // push
		{
			top++;
			strcpy(string[top], ptr);
			ptr = strtok(NULL, " ");
		}

		printf("Case #%d: ", i + 1);
		for (int i = top; i >= 0; i--)
		{
			if (i == 0)
			{
				printf("%s", string[i]);
				break;
			}
			printf("%s ", string[i]);
		}
		printf("\n");
	}

	return 0;
}