#include <stdio.h>

/*
	Question 1: Print all elemnts of array except self w / recursion, w/o division
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
int recursive_power(int base, int e)
{
	if (e == 0) // base case    
	{
		return 1;
	}

	else if (e >= 0)
	{
		return (base * recursive_power(base, e - 1)); //recursive case for e>=0
	}

	else if (e < 0)
	{
		return 1 / (recursive_power(base, -e)); // recursive case for e<0
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

	arrayProduct(array_A, 0, 1, n);  //recursive function call
	printf("\nThe final array status is as follows:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t\n\n", array_A[i]);
	}

	/*
	Quuestion 2
	*/
	int base;
	int e;
	int answer;

	printf("Hello there! Please enter a base number:\n ");
	scanf_s("%d", &base);
	printf("Great! Now enter the value of the power:\n ");
	scanf_s("%d", &e);
	answer = recursive_power(base, e);
	printf("%d to the power of %d is %d", base, e, answer);


	return 0;
}