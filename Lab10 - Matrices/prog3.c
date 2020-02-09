#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **Get_Mat(unsigned r, unsigned c); //Function declaration
void Set_Mat(int **p, unsigned r, unsigned c);
void Print_Mat(int **p, unsigned r, unsigned c);
void Mat_Mul(int **a, int **b, int **c, unsigned m, unsigned n, unsigned s);
void Free_Mat(int **m);

int main()
{
	srand(time(NULL)); //Calibrate random function to system time;
	int **m1, **m2, **m3, m, n, s; //Program variables
	printf("Enter 3 positive numbers please, (m, n and s respectively): "); //Asking the user for 3 integers, represents the matrix sizes
	scanf("%d %d %d", &m, &n, &s); //Getting user's integers
	m1 = Get_Mat(m, n); //Get memory from the system for program's 3 matrices
	m2 = Get_Mat(n, s);
	m3 = Get_Mat(m,s);
	Set_Mat(m1, m, n); //Setting random elemnts to #1 & #2 matrices
	Set_Mat(m2, n, s);
	Mat_Mul(m1, m2, m3, m, n, s); //Creating #3 matrix elemnts
	printf("m1:\n"); //Printing all matrices
	Print_Mat(m1, m, n);
	printf("m2:\n");
	Print_Mat(m2, n, s);
	printf("m3:\n");
	Print_Mat(m3, m, s);
	Free_Mat(m1); //Freeing matrices memory allocation
	Free_Mat(m2);
	Free_Mat(m3);
}

/*Function name: Get_Mat
Input: Two integers represents row and columns
Output: Pointer to the first slot of the 2d array
Algorithm: Creating pointer to first slot of array of pointers, than create each slot pointers*/
int **Get_Mat(unsigned r, unsigned c)
{
	int itt, **p;
	p = (int **)calloc(r, sizeof(int*));
	if (!p)
	{
		printf("ERROR: Not enough memory");
		exit(1);
	}
	p[0] = (int*)calloc(r*c, sizeof(int));
	if (!p[0])
	{
		printf("ERROR: Not enough memory");
		exit(1);
	}
	for (itt = 1; itt < r; itt++)
	{
		p[itt] = (int*)calloc(c, sizeof(int));
		if (!p[itt])
		{
			printf("ERROR: Not enough memory");
			exit(1);
		}
	}
	return p;
}
/*Function name: Set_Mat
Input: Pointer to first slot and 2 inetegers, represents rows and columns
Output: Matrix full of random numbers, of [-50,50]
Algorithm: Running with 2 for loops on the matrix, setting each slot to random number*/
void Set_Mat(int **p, unsigned r, unsigned c)
{
	int itt, jtt;
	for (itt = 0; itt < r; itt++)
	{
		for (jtt = 0; jtt < c; jtt++)
		{
			p[itt][jtt] = (50-rand()%101);
		}
	}
}
/*Function name: Print_Mat
Input: Pointer to first slot and 2 integers, represents rows and columns
Output: None
Algorithm: Running with 2 for loops on the matrix; printing each elemnt*/
void Print_Mat(int **p, unsigned r, unsigned c)
{
	int  itt, jtt;
	for (itt = 0; itt < r; itt++)
	{
		for (jtt = 0; jtt < c; jtt++)
		{
			printf("\t%d", p[itt][jtt]);
		}
		printf("\n");
	}
}
/*Function name: Mat_Mul
Input: 3 Pointers to first slots of each of them and the new matrix sizes
Output: None
Algorithm: Inserting the dot product of 2 vectors to each slot of the new matrix*/
void Mat_Mul(int **a, int **b, int **c, unsigned m, unsigned n, unsigned s)
{
	int itt, jtt, ktt, sum = 0;
	for (itt = 0; itt < m; itt++)
	{
		for (jtt = 0; jtt < s; jtt++)
		{
			for (ktt = 0; ktt < n; ktt++)
			{
				sum += (a[itt][ktt] * b[ktt][jtt]);
			}
			c[itt][jtt] = sum;
			sum = 0;
		}
	}
}
/*Function name: Free_Mat
Input: Pointer to matrix
Output: None
Algorithm: Freeing each of it's matrix pointer and then freeing the main pointer*/
void Free_Mat(int **m)
{
	int itt;
	for (itt = 0; itt < (sizeof(m)/sizeof(int)) ; itt++)
	{
		free(m[itt]);
	}
	free(m);
}
