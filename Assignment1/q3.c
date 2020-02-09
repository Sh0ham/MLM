#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
	int num, num1, num2, i, sum = 0; //Program variables
	char letter; //Current letter variable
	printf("Enter the number of digits in the Hexadecimal number: "); //Asking the user for the number of digits
	scanf("%d", &num); //Getting the number of digits		 
	num2 = num; //Using the number as the pow number
	printf("Enter the Hexadecimal number: "); //Asking the user for the number
	for (i = 0; i < num; i++) //Looping the number digit by digit
	{
		letter = getche(); //Implneting the charcter through the loop
		if ((letter >= 'a') && (letter <= 'f'))
			letter = letter - 87;
		else if ((letter > 'F') && (letter < 'a'))
		{
			printf("\nIligel input");
			getch();
		}
		else if (letter > 'f')
		{
			printf("\nIligel input");
			getch();
		}
		else if ((letter >= 'A') && (letter <= 'F'))
			letter = letter - 55;
		else
			letter = letter - 48;
		sum = sum + letter * pow(16, num2 - 1);
		num2--;
	}
	printf("\nThe decimal number is:%d", sum);
	getch();
}
