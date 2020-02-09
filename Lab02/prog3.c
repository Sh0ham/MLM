#include <stdio.h>   /*for printf and scanf function*/                        

void main()
{
	float high, base; //Declare user's height and base
	float area; //Decalre the area floating point number
	printf("Enter a triangle edge and its height respectively, please: "); //Printing the request
	scanf("%f %f", &high, &base); //Getting the numbers
	area = (high)*(base)*0.5; //Calculate the area
	printf("\nThe triangle area is %6.3lf", area); //Printing the result
	getch();
}
