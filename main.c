#include <stdio.h>

/*
	Question 1: Recursive print elemnts of array except self w/o division
*/
int arrayProduct(int array_A[], int i, int leftward_sequence, int n)
{
	int zero = array_A[5];
	zero = 0; // array element 5 prints set garbage value to 0
	int current_array_status;
	int rightward_sequence;
	int final_array_status;

	current_array_status = array_A[i]; // displays the original array values
	if (i == n) // base case
	{
		return 1;

	}
	rightward_sequence = arrayProduct(array_A, i + 1, leftward_sequence * array_A[i], n); //  product to the right of the index
	array_A[i] = leftward_sequence * rightward_sequence; // replace element [i] with product of left and right sequence
	final_array_status = current_array_status * rightward_sequence;
	//printf("%d\t", array_A[i]); // 

	return final_array_status;
}

/*
Question 2: Recursive power function w/ negative exponents
*/
int recursivePower(int base, int e)
{
	if (e == 0) // base case    
	{
		return 1;
	}

	else if (e >= 0)
	{
		return (base * recursivePower(base, e - 1)); //recursive case for e>=0
	}

	else if (e < 0)
	{
		return 1 / (recursivePower(base, -e)); // recursive case for e<0
	}

}
/*
Question 3: Recursive permutation 
*/
// swaps the characters in array
void swapElements(char array_x[], int i, int j) 
{
	char temp_value;
	temp_value = array_x[i];
	array_x[i] = array_x[j];
	array_x[j] = temp_value;
}

// recursive function to permute and print string
void permuteElements(char array_A[], int left, int space)
{
	int x;
	//char str[12];
	if (left == space) // base case
	{
		printf("\n%s\n", array_A);
	}

	else
	{
		for (x = left; x <= space; x++) // recursive case 
		{
			swapElements(array_A, left, x);
			permuteElements(array_A, left + 1, space);
			swapElements(array_A, left, x);
		}
	}
}


// main function
int main(void)
{
	/*
	Quuestion 1
	*/
	int array_A[] = { 1,2,3,4,5 };
	int n = 5;

	arrayProduct(array_A, 0, 1, n);  
	printf("\nThe final array status is as follows:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t\n\n", array_A[i]);
	}

	/*
	Question 2
	*/
	int base = 3;
	int e = 4;
	int answer;
	
	/*printf("Hello there! Please enter a base number:\n ");
	scanf_s("%d", &base);
	printf("Great! Now enter the value of the power:\n ");
	scanf_s("%d", &e);*/
	answer = recursivePower(base, e);
	printf("%d to the power of %d is %d\n", base, e, answer);

	/*
	Question 3
	*/
	int nn = 3;
	char string_A[] = "123";
	printf("\nThe final permuted array status is as follows:\n");
	permuteElements(string_A, 0, nn - 1);

	return 0;
}