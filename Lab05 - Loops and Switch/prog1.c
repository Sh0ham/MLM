#include <stdio.h>   /*for printf and scanf function*/
#include <math.h>

void main()
{
	int num, counter = 0, i = 1;
	printf("Enter an integer number, please: ");
	scanf("%d", &num);
	switch (num)
	{
		case 0:
		{
			printf("Infinity");
			break;
		}
		default:
		{
			if (num<0)
			{
				num *= (-1);
				for (i; i <= num; i++)
				{
					if (num%i == 0)
					{
						printf("%d ", i);
						counter++;
					}
				}
			}
			else
			{
				for (i; i < num; i++)
				{
					if (num%i == 0)
					{
						printf("%d ", i);
						counter++;
					}
				}
			}
			printf("\ncount=%d", counter);
		}
	}
}
