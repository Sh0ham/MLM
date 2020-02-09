#include <stdio.h>
#include <stdlib.h>

int **getMat(int order);
int perfectMat(int **matrix, int order);
void freeMat(int **matrix, int order);

int main()
{
	int **matrix, itt, jtt, order = 1;
	printf("Enter n, please: ");
	while ((scanf("%d", &order) == 1) && order > 0) //Length condition to check input is a positive integer
	{
		matrix = getMat(order);
		printf("Enter %dx%d matrix elemets, please:\n", order, order);
		for (itt = 0; itt < order; itt++)
		{
			for (jtt = 0; jtt < order; jtt++)
			{
				scanf("%d", &matrix[itt][jtt]);
			}
		}
		printf("\nMatrix\n");
		for (itt = 0; itt < order; itt++)
		{
			for (jtt = 0; jtt < order; jtt++)
			{
				printf("%6d", matrix[itt][jtt]);
			}
			printf("\n");
		}
		(perfectMat(matrix, order)) ? printf("is perfect.\n") : printf("is not perfect.\n");
		freeMat(matrix, order);
		printf("\nEnter n, please: ");
	}
	printf("Thank you for exploring perfect matrices.\n");
	return 0;
}

/*Function name: getMat
Input: One integer
Output: Pointer to the first slot of the matrix
Algorithm: Allocating memory for column vector and each slot represent row vector*/
int **getMat(int order)
{
	int itt;
	int **matrix = (int**)malloc(order * sizeof(int*));
	if (!matrix)
	{
		printf("Not enought memory");
		exit(1);
	}
	for (itt = 0; itt < order; itt++)
	{
		matrix[itt] = (int*)malloc(order * sizeof(int));
		if (!matrix[itt])
		{
			printf("Not enought memory");
			exit(1);
		}
	}
	return matrix;
}
/*Function name: getMat
Input: Pointer to the first slot of the matrix and it's order
Output: One or zero, depends on if given matrix is perfect
Algorithm: */
int perfectMat(int **matrix, int order)
{
	int itt, jtt, rowNum, colNum, expectedSum, rowSum = 0, colSum = 0; //Function variables
	int *stHodor = (int*)malloc(order * sizeof(int));
	int *ndHodor = (int*)malloc(order * sizeof(int));
	if (!stHodor || !ndHodor)
	{
		printf("Not enought memory");
		exit(1);
	}
	for (itt = 0; itt < order; itt++) //Setting the count arrays to zeros
	{
		stHodor[itt] = 0;
		ndHodor[itt] = 0;
	}
	expectedSum = order * (order+1)/2; //Setting the expected summary of rows
	for (itt = 0; itt < order; itt++) //Running on double for loop
	{
		for (jtt = 0; jtt < order; jtt++)
		{
			rowNum = matrix[itt][jtt];
			colNum = matrix[jtt][itt];
			if (rowNum > order || rowNum < 1 || colNum > order || colNum < 1)
			{
				return 0;
			}
			rowSum += rowNum; //Updating rows and columns summary
			colSum += colNum;
			stHodor[rowNum-1]++; //Updating the counter arrays
			ndHodor[colNum-1]++;
		}
		if (rowSum != expectedSum || colSum != expectedSum)
		{
			return 0;
		}
		rowSum = 0;
		colSum = 0;
	}
	for (itt = 0; itt < order; itt++)
	{
		if (stHodor[itt] != order || ndHodor[itt] != order)
		{
			return 0;
		}
	}
	free(stHodor);
	free(ndHodor);
	return 1;
}
/*Function name: freeMat
Input: Pointer to the first slot of the matrix and it's order
Output: None
Algorithm: Running with for loop realse memory allocated*/
void freeMat(int **matrix, int order)
{
	int itt; //Function variable declaration
	for (itt = 0; itt < order; itt++) //Running on matrix
	{
		free(matrix[itt]); //Relase each row memory allocated by program
	}
	free(matrix); //Relase the main column vector
}
