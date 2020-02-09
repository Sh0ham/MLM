#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int row, col, ittOne = 1, ittTwo = 1;
	printf("Insert dimensions: ");
	scanf("%d %d", &row, &col);
	for (ittOne; ittOne <= row; ittOne++)
	{
		for (ittTwo = 1; ittTwo <= col; ittTwo++)
		{
			printf("%5d", ittOne * ittTwo);
		}
		printf("\n");
	}
}
