#include <stdio.h>   /*for printf and scanf function*/                        

void main()
{
	char ch; //Decalre the char variable
	int differ = ('a'-'A'); //Declare and calculate the difference between capital and lower
	printf("Enter an English lower case letter, please: "); //Asking the user for input
	ch = getchar(); //Inserting user's letter
	printf("The ascii code of '%c' is %d.\n", ch, ch); //Printing lower case and ascii code
	printf("The ascii code of '%c' is %d.", ch-differ, ch-differ); //Printing upper case and ascii code
}