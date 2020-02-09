#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int num = 1; //Initlazing program variable
	while (num<=100) //Defining the while loop indicator
	{
		if ((num%7 == 0) || (num%10) == 7 || (num/10) == 7) //Logic condition finding the numbers including 7 or mult of 7
		{
			printf("BOOM "); //Printing result
		}
		else //All other normal numbers
		{
			printf("%d ", num); //Printing result
		}
		num++; //Counter update
	}
}
