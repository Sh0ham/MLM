#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void removeSpaces(char *str, char *strHodor); //Function declaration
void capitalLetters(char *str, char *strHodor);
void removeRepeated(char *str, char *strHodor);


int main()
{
	char str[N]; //Program variables
	char *strHodor = (char *)malloc((strlen(str)+1) * sizeof(char));
	if (strHodor)
	{
		fgets(str, N, stdin); //Getting user's string, protecting memory glitches
		removeSpaces(str, strHodor); //Fixing spaces inside string function
		capitalLetters(str, strHodor); //Fixing capital letters function
		removeRepeated(str, strHodor); //Remove duplicate words inside string function
		printf("The corrected sentence is:\n%s\n", str); //Printing user's corrected string
		free(strHodor); //Releasing the memory allocated by strHodor
	}
	else
	{
		printf("ERROR: Not enough memory!"); //Printing error (no exit(1) function needed)
	}
	return 0;
}

/*Function name: removeSpaces
Input: Pointer to first address of the string
Output: None
Algorithm: While loop counting how many space chars appear on start of the string, than starting for loop from this slot with it's condition fixing spaces*/
void removeSpaces(char *str, char *strHodor)
{
	int itt, jtt, counter = 0, flag = 1; //Function variables
	while (flag)
	{
		(str[counter] == ' ') ? (counter++) : (flag = 0); //Counting spaces before string started
	}
	for (jtt = 0, itt = counter; itt < (strlen(str)+1); itt++) //Copying the correct string to temp string
	{
		(str[itt] != ' ') ? ((strHodor[jtt] = str[itt]) && (jtt++)) : 0; //If current charcter is not space, taking the charcter
		(str[itt] == ' ' && str[itt+1] == '.') ? ((strHodor[jtt] = '.') && (jtt++) && (itt++) && (strHodor[jtt+1] = '\0')) : 0; //End of the string condition
		(str[itt] == ' ' && str[itt+1] == ',') ? ((strHodor[jtt] = ',') && (jtt++) && (itt++)) : 0; //If current charcter is space and next one is comma
		(str[itt] == ' ' && str[itt+1] != ' ') ? ((strHodor[jtt] = ' ') && (jtt++)) : 0; //If current and next charcters are spaces
		(str[itt] == ',' && str[itt+1] != ' ') ? ((strHodor[jtt] = ' ') && (jtt++)) : 0; //If current charcter is comma and next charcter isn't space
	}
	strcpy(str,strHodor); //Copying back the string to user's string
}
/*Function name: capitalLetters
Input: Pointer to first address of the string
Output: None
Algorithm: Setting first charcter to be capital, than running with for loop on each charcter setting it to lowercase*/
void capitalLetters(char *str, char *strHodor)
{
	int itt; //Function variable
	(str[0] >= 'a' && str[0] <= 'z') ? (str[0] -= ('a'-'A')) : 0; //Fixing first charcter if needed
	for (itt = 1; itt < strlen(str); itt++) //For loop running on the string
	{
		(str[itt] >= 'A' && str[itt] <= 'Z') ? (str[itt] += ('a'-'A')) : 0; //Setting all  charcters to lower case
	}
}
/*Function name: removeRepeated
Input: Pointer to first address of the string
Output: None
Algorithm: Tearing apart the string into words and with it's pointers compare letter by letter.
					 If different has been found pasting the word into the temporary string.*/
void removeRepeated(char *str, char *strHodor)
{
	strcpy(strHodor,str); //Copying the original string to temp string
	str[0] = '\0'; //Fixing user's string to hold nothing untill program paste words
	int itt, differ = 0; //Function variables
	char *currentWord, *lastWord;
	currentWord = strtok(strHodor, " "); //Splitting first words from the string
	strcat(strcat(str, currentWord), " "); //Paste first words into the temporary string and add a space after it
	while (currentWord != NULL) //As long as there more words in the string
	{
		lastWord = currentWord; //Last word holder
		currentWord = strtok(NULL," "); //Updating to next word
		if (currentWord != NULL) //If next word exists
		{
			for (itt = 0; itt < strlen(lastWord); itt++) //Running on for loop, compare each letter of current word and last word
			{
				lastWord[itt] != currentWord[itt] ? differ++ : 0; //If not the same raise the flag
			}
			(differ) ? strcat(strcat(str, currentWord)," ") : 0; //If words aren't the same, paste it into the temporary string with space after it
			differ = 0; //Zeroing the flag
		}
	}
	for (itt = 0; itt < strlen(str); itt++) //Running on for loop, find the dot at the end of the line
	{
		(str[itt] == '.') ? (str[itt+1] = '\0') : 0; //Set the end of the string right after the point
	}
}
