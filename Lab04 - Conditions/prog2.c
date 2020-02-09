#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int num, digit1, digit2, digit3, digit4, differ1, differ2, differ3; //Declare variables
	printf("Please enter a positive 4 digits number: "); //Asking the user for input
	scanf("%d", &num); //Getting the. User's input
	digit1 = num/1000; // Getting the first digit of the number
	digit2 = (num/100)%10; //Getting the second digit of the number
	digit3 = (num%100)/10; //Getting the third digit of the number
	digit4 = (num%100)%10; //Getting the fourth digit of the number
	differ3 = digit4-digit3; //Calculate the difference between the fourth and third digits
	differ2 = digit3-digit2; //Calculate the difference between the third and second digits
	differ1 = digit2-digit1; //Calculate the. Difference between the second and the first digits
	if ((num>=0 && num<1000) || num>9999) //Checking if the number is 4 digits
	{
		printf("%d is not a 4 digits number. Bye bye.\n", num); //Printing error for less than 4 digits or more than 4 digits numbers
	}
	if (num<0) //Checking if the number is negative
	{
		printf("%d is a negative number. Bye bye.\n", num); //Printing error for negative number
	}
	if (num>=1000 && num<=9999) //Checking for a valid number
	{
		if (digit1 == digit2 && digit2 == digit3 && digit3 == digit4) //Checking for number with equal digits
		{
			printf("All 4 digits are same.\n"); //Printing number type
		}
		if ((digit1!=digit2) || (digit2!=digit3) || (digit3!=digit4)) //Checking for number with at least one different digit
		{
			if ((digit1<=digit2) && (digit2<=digit3) && (digit3<=digit4)) //Checking for increasing series
			{
				if ((differ3 == differ2) && (differ2 == differ1)) //Checking for arithmetic series
				{
					printf("Increasing arithmetic sequence <from left to right>.\n"); //Printing the sequence type
				}
				if ((differ3 != differ2) || (differ2 != differ1)) //Checking for increasing and not arithmetic series
				{
					printf("Increasing sequence <from left to right>.\n"); //Printing sequence type
				}
			}
			if ((digit1>=digit2) && (digit2>=digit3) && (digit3>=digit4)) //Checking for decreasing series
			{
				if ((differ3 == differ2) && (differ2 == differ1)) //Checking for arithmetic series
				{
					printf("Decreasing arithmetic sequence <from left to right>.\n"); //Printing the sequence type
				}
				if ((differ3 != differ2) || (differ2 != differ1)) //Checking for decreasing and not arithmetic series 
				{
					printf("Decreasing sequence <from left to right>.\n"); //Printing the sequence type
				}	
			}
		}
		if ((digit2<digit3 && digit3>digit4) || (digit1<digit2 && digit3>digit4) || (digit3<digit2 && digit4>digit3) || (digit2<digit1 && digit4>digit3)) //Checking for every other sequences
		{
			printf("Nondecreasing and nonincreasing sequence.\n"); //Printing the sequence type
		}
	}
}
