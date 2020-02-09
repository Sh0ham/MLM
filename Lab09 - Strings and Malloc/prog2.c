#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
	char str[MAX]; //Initializing charcters array with 100 slots
	int itt, flag = 1, counter = 0; //Declaring program variables

	while (flag)
	{
		printf("Enter a string, please: "); //Asking user for input
		gets(str); //Reciving user's string
		flag = strlen(str); //Switching the flag indicator to string length
		rewind(stdin); //Correcting the input
		for (itt = 0; itt < flag; itt++) //For loop, running on the string
		{
			if (str[itt] != ' ' && str[itt] != '\t') //If current char isn't space
			{
				printf("%c", str[itt]); //Printing charcter
				counter++; //Increasing the space on start indicator
			}
			if ((counter != 0) && (str[itt] == ' ') && (str[itt+1] != ' ') && (str[itt+1] != '\0')) //If current char is space
			{
				printf("\n"); //Printing only once before real charcter
			}
		}
		printf("\n\n");
		counter = 0; //Zeroing the counter for next string
	}
	printf("Finish!"); //Exit the program
}
