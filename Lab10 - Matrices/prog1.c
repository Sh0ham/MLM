#include <stdio.h>
#define SIZE 5

int rowEqualElements(int matrix[][SIZE], int rows, int cols, int row); //Function declaration
int positiveDiagonal(int matrix[][SIZE], int rows, int cols);

int main()
{
	int matrix[SIZE][SIZE]; //Initializing matrix N*N
	int itt, jtt, rowEqual = 0; //Program variables
	printf("Please enter %dx%d matrix elements: \n", SIZE, SIZE); //Asking the user for elements
	for (itt = 0; itt < SIZE; itt++) //Running with 2 for loops, getting user's elements
	{
		for (jtt = 0; jtt < SIZE; jtt++)
		{
			scanf("%d", &matrix[itt][jtt]);
		}
	}
	printf("\nMatrix\n"); //Running with 2 for loops; printing the matrix once user done
	for (itt = 0; itt < SIZE; itt++)
	{
		for (jtt = 0; jtt < SIZE; jtt++)
		{
			printf("%5d", matrix[itt][jtt]);
		}
		printf("\n");
	}
	for (itt = 0; itt < SIZE; itt++)
	{
		rowEqual += rowEqualElements(matrix, SIZE, SIZE, itt);
	}
((rowEqual == SIZE) && (positiveDiagonal(matrix, SIZE, SIZE) == 1)) ? printf("is OK") : printf("isn't OK"); //Checking with program functions
}

/*Function name: rowEqualElements
Input: Matrix with size of N*N
Output: 1 or 0
Algorithm: Summary each row and comparing it to the itterator*/
int rowEqualElements(int matrix[][SIZE], int rows, int cols, int row)
{
	int itt, sum = 0; //Function variables
	for (itt = 0; itt < cols; itt++) //Row for loop
	{
		sum += matrix[row][itt]; //Summary the row
	}
	return (sum == row) ? 1 : 0; //Checking if sum equal the itterator
}
/*Function name: positiveDiagonal
Input: Matrix with size of N*N
Output: 1 or 0
Algorithm: Running with for loop on each [I,I] slot, check if bigger than 0*/
int positiveDiagonal(int matrix[][SIZE], int rows, int cols)
{
	int itt, counter = 0; //Function variable
	for (itt = 0; itt < SIZE; itt++) //Running on for loop, check if [I,I] element greater than zero
	{
		(matrix[itt][itt] > 0) ? (counter++) : 0;
	}
	return ((counter == SIZE) ? 1 : 0); //Return 1 iff every element is greater than zero
}
