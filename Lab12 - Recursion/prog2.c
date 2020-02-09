#include <stdio.h>
#include <stdlib.h>
#define LEN 256
int recursiveHasPrefix(char *str, char *prefix);

int main ()
{
	char str[LEN+1];
	char pre[LEN+1];
	int isPrefix=1;
	while(isPrefix) /* As long as pre is a predix of str */
	{
		printf("Please enter a string: "); /*input two strings*/
		gets_s(str, LEN);
		printf("Please enter a prefix string: ");
		gets_s(pre, LEN);
		isPrefix = recursiveHasPrefix(str, pre);/*check whether pre is a prefix of str.*/
		if(isPrefix) printf("The specific text has the prefix.\n\n");
		else printf("No prefix.\n\n");
	}
	return 0;
}

/*Function name: recursiveHasPrefix
Input: Two pointers to start of the strings
Output: 1 or 0, Depends second string is prefix of first
Algorithm: Comapring each slot of both strings from the first one to last,
						untill prefix ends.*/
int recursiveHasPrefix(char *str, char *prefix)
{
	return (*prefix != '\0') ? ((*str++ == *prefix++) && recursiveHasPrefix(str, prefix)) : 1;
}
