#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uniqueAppearance(char *st1, char *st2, char *st3);

int main()
{
	int itt, length, rdStringLength, capitalFlag = 1, sizeFlag = 1; //Program variables declaration
	char *st1, *st2, *st3;
	printf("Please enter an integer number of maximum size of a string: "); //Asking the user for length of strings
	while ((scanf("%d", &length) != 1) || length < 1) //Length condition to check input is a positive integer
	{
		printf("ERROR: Only positive integers allowed. Try again: ");
		rewind(stdin);
	}
	st1 = (char *)malloc(length * sizeof(char)); //Allocation memory for both strings with "length" slots
	st2 = (char *)malloc(length * sizeof(char));
	if (st1 && st2) //Memory allocation failed
	{
		rdStringLength = (strlen(st1)+strlen(st2));
		while (capitalFlag || sizeFlag) //First string conditions
		{
			capitalFlag = 0;
			sizeFlag = 0;
			printf("Please enter the first string containing no more than %d lower case English letters: ", length);
			rewind(stdin);
			gets(st1);
			for (itt = 0; itt < strlen(st1); itt++)
			{
				(st1[itt] < 'a' || st1[itt] > 'z') ? capitalFlag++ : 0; //Failed lower case test
				(strlen(st1) > length) ? sizeFlag++ : 0; //Failed length test
			}
			(capitalFlag > 0) ? printf("Illegal input: the string must contain only lower case English letters\n") : 0; //Printing lowercase error
			((capitalFlag == 0) && (sizeFlag > 0)) ? printf("Illegal input: the string must contain no more than %d lower case English letters\n", length) : 0; //Printing length error
		}
		capitalFlag = 1; //Updating the conditions for the next string
		sizeFlag = 1;
		while (capitalFlag || sizeFlag) //First string conditions
		{
			capitalFlag = 0;
			sizeFlag = 0;
			printf("Please enter the second string containing no more than %d lower case English letters: ", length);
			rewind(stdin);
			gets(st2);
			for (itt = 0; itt < strlen(st2); itt++)
			{
				(st2[itt] < 'a' || st2[itt] > 'z') ? capitalFlag++ : 0; //Failed lower case test
				(strlen(st2) > length) ? sizeFlag++ : 0; //Failed length test
			}
			(capitalFlag > 0) ? printf("Illegal input: the string must contain only lower case English letters\n") : 0; //Printing lowercase error
			((capitalFlag == 0) && (sizeFlag > 0)) ? printf("Illegal input: the string must contain no more than %d lower case English letters\n", length) : 0; //Printing length error
		}
		st3 = (char *)malloc(rdStringLength * sizeof(char)); //Allocation memory for third string, with the length of both strings summary
		if (st3)
		{
			uniqueAppearance(st1, st2, st3);
			printf("%s", st3);
			free(st2);
			free(st1);
		}
		free(st3);
	}
	return 0;
}

/*Function name: uniqueAppearance
Input: Three pointers to first address of strings
Output: None
Algorithm: Running on third string, which combined from both string #1 & #2, updating the counter array.
Than running on counter array and each time slot is bigger than zero, adding the letter to string #3
At last setting ending string flag*/
void uniqueAppearance(char *st1, char *st2, char *st3)
{
	int itt, jtt = 0; //Function variables
	int strCounter[26] = { 0 }; //Array with slots as many as English letters
	strcpy(st3, st1); //Copying both strings to string #3
	strcat(st3, st2);
	for (itt = 0; itt < strlen(st3); itt++) //Running on st3
	{
		strCounter[(st3[itt] - 'a')]++; //updating counting array
	}
	for (itt = 0; itt < 26; itt++)
	{
		(strCounter[itt]) ? ((st3[jtt] = (char)(itt + 'a')) && (jtt++)) : 0; //Updating st3
	}
	st3[jtt] = '\0'; //Setting ending point to st3
}
