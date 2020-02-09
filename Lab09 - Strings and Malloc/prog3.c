#include <stdio.h>
#include <string.h>
#define MAX 100

void replaceSubstring(char *str, char *substr); //Function declaration

int main()
{
	char str[MAX], substr[MAX]; //Initializing charcters arrays with 100 slots
	int flag = 1; //Declaring program variable
	while (flag) //Infinite loop, till one of the strings is empty
	{
		printf("Enter text: "); //Asking the user for string
		gets(str); //Reciving user's string
		flag = strlen(str); //Changing the indicator to 1st string length
		if (flag) //Continue only if the string isn't empty
		{
			printf("Enter substring: "); //Asking the user for 2nd string
			gets(substr); //Reciving user's string
			flag = strlen(substr); //Changing the indicator to 2nd string length
			if (flag) //Continue only if the string isn't empty
			{
				replaceSubstring(str, substr); //Replacing the term with capital letters function
			}
		}
	}
	printf("Finish"); //Exit the program
}

/*Function name: replaceSubstring
Input: Two strings
Output: None
Algorithm: While loop with common words condition, replacing capital letters of common words*/
void replaceSubstring(char *str, char *substr)
{
	int itt, flagSubStr = strlen(substr); //Initializing function variables
	char *strString = strstr(str, substr);
	char ch;
	while (strString) //Works only if the string has common words
	{
		for (itt = 0; itt < flagSubStr; itt++, strString++) //For loop running on common word chars array
		{
			ch = *strString;
			*strString = ((ch >= 'a') && (ch <= 'z')) ? (ch - 32) : ch; //Replacing letters with capital
		}
		strString = strstr(str+1, substr);
	}
	puts(str); //Printing the string with capitals
	printf("\n");
}
