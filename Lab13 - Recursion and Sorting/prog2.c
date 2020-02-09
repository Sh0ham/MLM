#include <stdio.h>

unsigned build(unsigned num, unsigned mask);

int main()
{
	unsigned long num, mask;
	int itt;
	for (itt = 0; itt < 4; itt++)
	{
		printf("Please enter 2 unsigned, a number and a mask, respectively: ");
		scanf("%d %d", &num, &mask);
		printf("After applying mask %u on %u we get: %u.\n", num, mask, build(num, mask));
	}
	return 0;
}
/*Function name: build
Input: Two unsigned integers
Output: Unsigned integer masked
Algorithm: */
unsigned build(unsigned num, unsigned mask)
{
	return (mask == 0) ? 0 : ((mask % 10 == 1) ? ((num%10)+(10*(build(num/10,mask/10)))) : (10*build(num/10, mask/10)));
}
