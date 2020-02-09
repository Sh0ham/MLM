#include <stdio.h>
#define N 4
#define M 5

void shift(int matrix[N][M]); //Function declaration

int main()
{
	int matrix[N][M] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}}; //Initializing matrix
	int itt, jtt, ktt; //Program variables
	for (itt = 0; itt < N; itt++) //Running with 2 for loops; printing the matrix
	{
		for (jtt = 0; jtt < M; jtt++)
		{
			printf("%5d", matrix[itt][jtt]);
		}
		printf("\n");
	}
	for (ktt = 0; ktt < 3; ktt++) //Running with for loop rotate and print 3 times
	{
		printf("Shift %d:\n", (ktt+1));
		shift(matrix);
		for (itt = 0; itt < N; itt++)
		{
			for (jtt = 0; jtt < M; jtt++)
			{
				printf("%5d", matrix[itt][jtt]);
			}
			printf("\n");
		}
	}
}

/*Function name: Shift
Input: Matrix with size of N*N
Output: Rotated matrix with 1 spot to the right
Algorithm: Holding the last matrix variable and then shifting*/
void shift(int matrix[N][M])
{
	int hodorix[N-1];
	int itt, jtt, hodor = matrix[N-1][M-1];
	for (itt = 0; itt < (N-1); itt++)
	{
		hodorix[itt] = matrix[itt][M-1];
	}
	for (itt = 0; itt < N; itt++)
	{
		for (jtt = (M-1); jtt > 0; jtt--)
		{
			matrix[itt][jtt] = matrix[itt][jtt-1];
		}
	}

	matrix[0][0] = hodor;
	for (itt = 1; itt < N; itt++)
	{
		matrix[itt][0] = hodorix[itt-1];
	}
}
