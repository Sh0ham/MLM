#include <stdio.h>

int lengthOfString(char *s);

int main()
{
	char *text = "Experimental text to test recursive function.";
  printf("Length of string: \n%s\nis %d.\n", text, lengthOfString(text));
  return 0;
}

/*Function name: lengthOfString
Input: Pointer to string
Output: Length of string
Algorithm: Counting charcters one by one recursively*/
int lengthOfString(char *s)
{
	int sum = 0; //Function variable
	return (*s != '\0') ? (sum+((*s++ != '\0') + lengthOfString(s))) : 0;
}
