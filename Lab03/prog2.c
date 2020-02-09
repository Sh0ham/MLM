#include <stdio.h>	/*for printf and scanf function*/    
#include <math.h>	/*for the math functions*/                    

void main()
{
	float num;
	printf("Enter x please: ");
	scanf("%f", &num);
	printf("x+(1/3x^4+2x^(1/2))^(1/5) = %g+(1/3*%g^4+2*%g^(1/2))^(1/5) = %g" ,num,num,num,(num)+pow(((pow(num,4))/(3.0) + (4/2)*(pow(num,0.5))),0.2)
);
}




