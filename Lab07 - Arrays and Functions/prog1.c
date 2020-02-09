#define N 20
#include <stdio.h>

int addNums(int array[]);
int main()
{
	int i, array[N]; //Decleration the array set to N (20) slots
	printf("Enter 20 integers, please: ");
	for (i = 0; i<N; i++)
		scanf("%d", &array[i]); //Getting user's input for array
	printf("\n The sum is:%d\n", addNums(array)); //Printing the sum of all the numbers, using addNums function
	return 0;
}
int addNums(int array[])
{
	int i, sum = 0;
	for (i = 0; i < N; i++)
		sum = sum + array[i]; //Summary the i spot of the array

	return sum; //Function return total summary
}
