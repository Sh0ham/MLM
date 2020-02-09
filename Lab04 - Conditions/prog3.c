#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int a,b,c,d; //Declare variable for user's and compution
	printf("Enter 2 integers, please: "); //Asking the user for input
	scanf("%d %d", &a, &b); //Getting user's input
	c = b*(-1); //Comparison variable
	printf("%d and %d are opposite numbers (1 for true, 0 for false): ", a, b); //printing the result message
	d = (a==c); //Result variable
	printf("%d", d); //Printing the result
}
