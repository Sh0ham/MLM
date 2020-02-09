#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int weight, height; //Declare variables represents user's input
	float bmi; //Declare variable for calculation
	printf("Please enter weight (in kg) and height (in cm), respectively: "); //Asking for user's input
	scanf("%d %d", &weight, &height); //Getting user's input
	bmi = ((float)weight/(float)height/(float)height)*10000; //Calculation
	if (bmi<18.5)
	{
		printf("Underweight");
	}
	if (bmi>=18.5 && bmi<25)
	{
		printf("Normal weight");
	}
	if (bmi>=25.0 && bmi<30)
	{
		printf("Increased weight");
	}
	if (bmi>=30.0 && bmi<40.0)
	{
		printf("Obese");
	}
	if (bmi>=40.0)
	{
		printf("Very high obese");
	}
}
