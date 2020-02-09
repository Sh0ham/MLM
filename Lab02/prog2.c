#include <stdio.h>   /*for printf and scanf function*/                        

void main()
{
	int anum, bnum, cnum; //Declare 3 intergers
	printf("Enter a,b,c:"); //Asking the user for his numbers
	scanf("%d %d %d", &anum, &bnum, &cnum); //Getting te user numbers
	printf("y=a*2+b^2+c=(%d)*2+(%d)^2+%d=%d\n", anum, bnum, cnum, (anum*2)+(bnum*bnum)+(cnum)); //Printing the formula and the calculation
	getch();
}
