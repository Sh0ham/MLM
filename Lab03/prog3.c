#include <stdio.h>	/*for printf and scanf function*/     
#include <math.h>	/*for the math functions*/                   

void main()
{
	float num1, num2; //Declare the 2 real numbers
	printf("Given the equation a^x=b\nEnter a and b, respectively please: "); //Asking the user for the numbers
	scanf("%f %f", &num1, &num2); //Getting the numbers
	printf("x is: %g", log(num2)/log(num1)); //Calculate the log
}