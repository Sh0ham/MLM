#include <stdio.h>

char is_tripple(char *str); //Function declaration

int main()
{
	char str[30], letter; //Program variable
	printf("String: "); //Asking user's for input
	gets(str); //Getting user's input
	letter = is_tripple(str); //Getting the tripple charcter if exists
	(letter) ? (printf("In \"%s\", there is \"%c%c%c\"!\n", str, letter, letter, letter)) : (printf("In \"%s\", there is No Triple!\n", str)); //Printing result
	return 0; //Exit program
}

/*Function name: is_tripple
Input: Pointer to start of the given string
Output: Charcter that appear three times consecutive atleast on string
Algorithm: Comparing first  charcter with the second and third charcters, if failed calling the function once again and move to next slot*/
char is_tripple(char *str)
{
	return (str == '\0') ? ('\0') : (((str[0] == str[1]) && (str[0] == str[2])) ? *str : is_tripple(str+1));
}
