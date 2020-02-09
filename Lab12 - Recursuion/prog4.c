#include <stdio.h>

int recSeriesElem(unsigned n);

int main()
{
	int itt;
	printf("The first 12 elements in the series are:\n");
	printf(" ");
	for (itt = 0; itt < 12; itt++)
	{
		printf("%5d", recSeriesElem(itt));
	}
	return 0;
}

/*Function name: recSeriesElem
Input: Unsigned integer
Output: N-th number of the series defined by recurrence relation
Algorithm: */
int recSeriesElem(unsigned n)
{
	int stElement, ndElement;
	if (n < 3)
	{
		return n;
	}
	stElement = recSeriesElem(n-1);
	ndElement = recSeriesElem(n-2);
	return (3*stElement - 4*ndElement);
}
