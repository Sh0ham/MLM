#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 10

void initRandomArray(int arr[][COLUMNS]);
void printArray(int arr[][COLUMNS]);
void sortArray(int arr[][COLUMNS]);
void SortInColumn(int arr[][COLUMNS], int col);
void SortColumns(int arr[][COLUMNS]);
int compareColumns(int arr[][COLUMNS], int col1, int col2);
void swapColumns(int arr[][COLUMNS], int col1, int col2);

int main()
{
	int matrix[ROWS][COLUMNS]; /*= {{3,18,7,14,17,11,2,3,1,11},{5,6,6,12,5,16,12,10,1,2},{15,12,7,1,7,13,17,1,15,2},{13,9,8,5,7,0,17,3,11,14},{13,4,10,9,3,9,17,16,0,9}};*/
	initRandomArray(matrix);
	printf("Before sorting:\n");
	printArray(matrix);
	printf("\n");
	printf("After sorting elements in each column:\n");
	sortArray(matrix);
	printArray(matrix);
	printf("\n");
	printf("After sorting columns:\n");
	SortColumns(matrix);
	printArray(matrix);
	return 0;
}

/*Function name: initRandomArray
Input: Two demension array
Output: None
Algorithm: Running with two for loops, setting each slot to random value*/
void initRandomArray(int arr[][COLUMNS])
{
	int itt, jtt; //Function variables
	srand(time(NULL)); //Reset the rand function to current time
	for (itt = 0; itt < ROWS; itt++) //Running on each slot of the matrix, initialize a value
	{
		for (jtt = 0; jtt < COLUMNS; jtt++)
		{
			arr[itt][jtt] = rand() % 21; //Each slot setted to random value from 0 to 20
		}
	}
}
/*Function name: printArray
Input: Two demension array
Output: None
Algorithm: Running with two for loops, printing each slot*/
void printArray(int arr[][COLUMNS])
{
	int itt, jtt; //Function variables
	for (itt = 0; itt < ROWS; itt++) //Running on each slot of the matrix
	{
		for (jtt = 0; jtt < COLUMNS; jtt++)
		{
			printf("%5d ", arr[itt][jtt]); //Printing the integer
		}
		printf("\n"); //Printing new line
	}
}
/*Function name: sortArray
Input: Two demension array
Output: None
Algorithm: Running with for loop on each column, sorting it with SortInColumn function*/
void sortArray(int arr[][COLUMNS])
{
	int itt; //Function variable
	for (itt = 0; itt < COLUMNS; itt++)
	{
		SortInColumn(arr, itt);
	}
}
/*Function name: SortInColumn
Input: Two demension array
Output: None
Algorithm: Running with two for loops, comapring each slot to the next one; if it's larger swaping between them*/
void SortInColumn(int arr[][COLUMNS], int col)
{
	int itt, jtt, hodor; //Function variables
	for (itt = ROWS - 1; itt > 0; itt--) //Running on the column vector
	{
		for (jtt = 0; jtt < itt; jtt++) //Comapring each slot
		{
			if (arr[jtt][col] > arr[itt][col])
			{
				hodor = arr[itt][col]; //Temporary variable holding the value
				arr[itt][col] = arr[jtt][col]; //Swaping
				arr[jtt][col] = hodor; //Temporary value set back
			}
		}
	}
}
/*Function name: SortColumns
Input: Two demension array
Output: None
Algorithm: Running with two for loops on row vector, comapring each column with it's next with compareColumns function*/
void SortColumns(int arr[][COLUMNS])
{
	int itt, jtt; //Function variables
	for (itt = COLUMNS - 1; itt>0; itt--)
	{
		for (jtt = 0; jtt < itt; jtt++)
		{
			compareColumns(arr, jtt, itt);
		}
	}
}
/*Function name: compareColumns
Input: Two demension array and two integers represents two indices
Output: KEREN, WHY INT FUNCTION?!
Algorithm: Running with while loop till found different values, if first is larger - swaping*/
int compareColumns(int arr[][COLUMNS], int col1, int col2)
{
	int itt = 0, jtt = 0; //Function variables
	while (arr[itt][col1] == arr[jtt][col2])
	{
		itt++;
		jtt++;
	}
	(arr[itt][col1] > arr[jtt][col2]) ? swapColumns(arr, col1, col2) : 0; //Swaping
	return 0;
}
/*Function name: swapColumns
Input: Two demension array and two integers represents two indices
Output: None
Algorithm: Running with for loop; Swaping using temporary variable*/
void swapColumns(int arr[][COLUMNS], int col1, int col2)
{
	int itt = 0, jtt = 0, hodor; //Function variables
	for (itt = 0; itt < ROWS; itt++, jtt++)
	{
		hodor = arr[jtt][col2]; //Temporary variable holding the value
		arr[jtt][col2] = arr[itt][col1]; //Swaping
		arr[itt][col1] = hodor; //Temporary value set back
	}
}
