#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
	char letter = 's'; //Declration of the char program variable
	int num1, num2;
	while (letter != 'q' && letter != 'Q') 
	{
		printf("\nEnter a charcter, please: "); //Asking the user for operator
		letter = getche(); //Getting the operator from the user
		switch (letter) //Switch case
		{
			case 'A': //Average operator upper case
			case 'a': //Abverage operator lower case
			{
				printf("\nEnter 2 integer numbers, please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				printf("The average of %d and %d, %f, ", num1, num2, (float)((num1+num2)/2.0)); //Calculating the average
				if (((num1+num2)/2) == ((float)(num1+num2)/2)) //Checking if the result is an inetger
				{
					printf("is an integer.\n");
				}
				else //Result is not an integer
				{
				printf("is not integer.\n");
				}
				break;
			}
			case '*': //Multiplication operator
			{
				printf("\nEnter 2 integer numbers, please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				printf("The product of %d and %d is %d.\n", num1, num2, (num1*num2)); //Printing the product result
				break;
			}
			case 'm': //Minimum operator
			{
				printf("\nEnter 2 integer numbers, please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				printf("The minimum number of %d and %d is %d\n", num1, num2, (num1>num2 ? num2 : num1)); //Printing the minimum
				break;
			}
			case 'M': //Maximum operator
			{
				printf("\nEnter 2 integer numbers, please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				printf("The maximum number of %d and %d is %d\n", num1, num2, (num1>num2 ? num1 : num2)); //Printing the maximum
				break;
			}
			case '^': //Power operator
			{
				printf("\nEnter 2 integer numbers (the base and the exponent respectively), please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				if (num1 == 0) //Domain defenitaion
				{
					printf("%d^%d is undefined", num1, num2); //Printing result
				}
				else
				{
					if ((pow(num1,num2)) == (float)(pow(num1,num2))) //Checking if the result is an inetger
					{
						printf("%d^%d=%d is an integer\n", num1, num2, (int)pow(num1,num2));
					}
					else //Result is not an inetger
					{
					printf("%d^%d=%f is not integer\n", num1, num2, pow(num1,num2));
					}
				}
				break;
			}
			case 'L': //Logarithm operator upper case
			case 'l': //Logarithm operator lower case
			{
				printf("\nEnter 2 integer numbers (a number to  compute the logarithm and the logarithm base respectively), please: "); //Asking the user for input
				scanf("%d %d", &num1, &num2); //Getting the input from the user
				if (num2 == 1 || num2 <= 0 || num1 <= 0) //Domain defenitaion
				{
					printf("Undefined\n");
				}
				else
				{
					if (((int)(log(num1)/log(num2))) == ((float)(log ((float)(num1))/log((float)(num2))))) //Checking if the result is an integer
					{
						printf("log(%d) in base %d, %d is an integer\n", num1, num2, (int)(log(num1)/log(num2)));
					}
					else //Result is not an integer
					{
						printf("log(%d) in base %d, %f is not integer\n",num1, num2, (float)(log(num1)/log(num2)));
					}
				}
				break;
			}
			default: //Wrong operator charcter
			{
				printf("\nError\n");
				break;
			}
			case 'Q':
			{
				letter = 'Q';
			}
			case 'q':
			{
				letter = 'q';
				break;
			}
		}
	}
	printf("\nFinish"); //End of program print
}
