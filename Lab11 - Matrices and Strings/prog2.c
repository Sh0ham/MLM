#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hiddenStr(char str1[], char str2[]); //Function declaration
char *revStr(char *str);


int main()
{
	char str1[] = "optic"; //Program variables declaration
	char str2[] = "nirto";
	char str3[] = "option";
	char str4[] = "Computer Science";
	printf("\n");
	(hiddenStr(str1, str4) || hiddenStr(revStr(str1), str4)) ? printf("\"optic\" is hidden in \"Computer Science\"\n") : printf("\"optic\" is not hidden in \"Computer Science\"\n"); //Comapring first and fourth string
	(hiddenStr(str2, str4) || hiddenStr(revStr(str2), str4)) ? printf("\"nirto\" is hidden in \"Computer Science\"\n") : printf("\"nirto\" is not hidden in \"Computer Science\"\n"); //Comapring second and fourth string
	(hiddenStr(str3, str4) || hiddenStr(revStr(str3), str4)) ? printf("\"option\" is hidden in \"Computer Science\"\n") : printf("\"option\" is not hidden in \"Computer Science\"\n"); //Comapring third and fourth string
	return 0;
}

/*Function name: hiddenStr
Input: Two strings
Output: One or zero, depends of given string hidden in second one
Algorithm: Creating two strings and with reversed string and comparing each string to given one*/
int hiddenStr(char str1[], char str2[])
{
	int itt, length; //Function variables
	char *stHodor = str1;
	char *ndHodor = str2;
	length = strlen(str1);
	for (itt = 0; itt < length; itt++, stHodor++)
	{
		ndHodor = strchr(ndHodor, *stHodor);
		if (!ndHodor)
		{
			return 0;
		}
	}
	return 1;
}
/*Function name: revStr
Input: First slot of string pointer
Output: First slot of reversed string pointer
Algorithm: Bitwise comparing and reversing*/
char *revStr(char *str)
{
	char *p1, *p2; //Function variables declaration
	for ((p1 = str, p2 = str + strlen(str) - 1); (p2 > p1); (++p1, --p2)) //Running on given string
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}
