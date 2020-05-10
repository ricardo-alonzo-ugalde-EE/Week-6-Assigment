/*
Week 6 Assigment
*/

#include <stdio.h>
#include <string.h>

// function to swap the values at two pointers

void character_swap(char* x, char* y)
{
	char temp = x;
	x = y;
	y = temp;
}

// Function to print all permutations of a string

void permutation_print(char *a, int b, int c)
{
	if (b == c)
	{
		printf("%s\n", a);
	}
	else
	{
		for (int i = 1; i <= c; i++)
		{
			character_swap((a + b), (a + i));
			permutation_print(a, b + i, c);
			character_swap((a + b), (a + i));
		}
	}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permutation_print(str, 0, n - 1);
	return 0;
}