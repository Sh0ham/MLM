#include <stdio.h>
#include <string.h>
#define N 4
void printReversedFromTo(char *str, int from, int len);
int main() {
	char *text = "Experimental text to print reversed fragment.";
	int i, len = strlen(text);
	int From_Vec[4] = { 0, 0, 10, 22 },
		To_Vec[N] = { len - 1, len / 2, len - 1, 33 };
	for (i = 0; i < N; i++) {
		printf("*** Reversed from %d to %d:\n", From_Vec[i], To_Vec[i]);
		printReversedFromTo(text, From_Vec[i], To_Vec[i]);
		printf("\n");
	}
	printf("\n*** Finish.\n");
	return 0;
}

/*Function name: printReversedFromTo
Input: Pointer to start of the string, and two integers represents it's start and end slots
Output: None
Algorithm: */
void printReversedFromTo(char *str, int from, int len)
{
	if (len-from >= 0)
	{
		printf("%c", str[len]);
		printReversedFromTo(str, from, len-1);
	}
}
