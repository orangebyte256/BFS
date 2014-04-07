#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 100

int main()
{
	FILE *f = fopen("input.txt", "w");
	int i = 0;
	int j = 0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (i != j)
				fprintf(f, "%d %d\n", i + 1, j + 1);
		}
	}
	fclose(f);
}