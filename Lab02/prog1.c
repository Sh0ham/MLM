#include <stdio.h>   /*for printf and scanf function*/                        

void main()
{
	int num; //User's number
	printf("Enter number: "); //Asking the user for his number
	scanf("%d", &num); //Getting the number
	printf("\nNumber      Square     Cube"); //Printing tittle
	printf("\n%4d %11d %10d", num, num*num, num*num*num); //Calculate and print user's number, square and cube
	printf("\n%4d %11d %10d", num+1, (num + 1)*(num + 1), (num + 1)*(num + 1)*(num + 1)); //Calculate and print the next number, square and cube
	printf("\n%4d %11d %10d", num + 2, (num + 2)*(num + 2), (num + 2)*(num + 2)*(num + 2)); //Calculate and print the second next number, square and cube
	printf("\n%4d %11d %10d", num + 3, (num + 3)*(num + 3), (num + 3)*(num + 3)*(num + 3)); //Calculate and print the third next number, square and cube
	printf("\n%4d %11d %10d\n", num + 4, (num + 4)*(num + 4), (num + 4)*(num + 4)*(num + 4)); //Calculate and print the fourth next number, square and cube
	getch();
}
