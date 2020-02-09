/**********************************************************************
*,ggggggggggggggg                                                     *
*dP""""""88"""""""                                    ,dPYb,          *
*Yb,_    88                                           IP'`Yb          *
*`""    88              gg                           I8  8I           *
*			 88              ""                           I8  8'            *
*			 88   ,gggggg,   gg   gg,gggg,    gg,gggg,    I8 dP   ,ggg,     *
*			 88   dP""""8I   88   I8P"  "Yb   I8P"  "Yb   I8dP   i8" "8i    *
* gg,   88  ,8'    8I   88   I8'    ,8i  I8'    ,8i  I8P    I8, ,8I   *
*	"Yb,,8P ,dP     Y8,_,88,_,I8 _  ,d8' ,I8 _  ,d8' ,d8b,_  `YbadP'    *
*		"Y8P' 8P      `Y88P""Y8PI8 YY88888PPI8 YY88888P8P'"Y88888P"Y888   *
*														I8          I8                            *
*														I8          I8                            *
*														I8          I8                            *
**********************************************************************/
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
