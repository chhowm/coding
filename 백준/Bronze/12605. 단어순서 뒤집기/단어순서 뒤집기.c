#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN 51
int main()
{
	int N;
	scanf("%d", &N);
	getchar();

	char inputString[LEN];
	for (int i=0; i<N; i++)
	{
		fgets(inputString, LEN, stdin);
		inputString[strlen(inputString) - 1] = '\0';
		//printf("%s", inputString);
		printf("Case #%d: ", i+1);
		int space = strlen(inputString);
		for (int j = strlen(inputString)-1; j>=0; j--)
		{
			if (inputString[j] == ' ')
			{
				for (int k = j + 1; k < space; k++)
				{
					printf("%c", inputString[k]);
				}
				printf(" ");
				space = j;
			}
			if (j == 0)
			{
				int l = 0;
				while (inputString[l] != ' ' && inputString[l] != '\0')
				{
					printf("%c", inputString[l]);
					l++;
				}
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
