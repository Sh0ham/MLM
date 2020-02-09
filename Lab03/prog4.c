#include <stdio.h>   /*for printf and scanf function*/
#include <math.h>
#define PI 3.14159265358979323846

void main()
{
	float alpha, base, volume, diagonal, height; //Declare the variables
	printf("Enter the pyramid base edge (in centimeters), please: "); //Asking the user to insert the base length
	scanf("%f", &base); //Getting user's length
	printf("Enter the angle (in degrees) between the pyramid side edge and its height, please: "); //Asking the user to insert the angle
	scanf("%f", &alpha); //Getting user's angle
	diagonal = base*sqrt(2)*0.5; //Calculate the half of the square diagonal
	height = (diagonal)/tan(alpha*PI/180); //Calculate the height length

	volume = pow(base,2)*height/3; //Calculate the volume
	printf("The volume (in cubic centimeters) of the pyramid is %.3f\n", volume); //Printing the volume
}
