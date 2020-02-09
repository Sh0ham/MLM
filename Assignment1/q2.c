#include <stdio.h>   /*for printf and scanf function*/

void main()
{
	int exam = 0, numOfHw = 0, hwNum = 0, hwSum = 0, excGrade = 0, i=0; //Program variables
	float grade; //Grade score
	scanf("%d %d", &exam, &numOfHw); //Getting user info
	for (i; i <= numOfHw-1; i++) //Scanning homework grades
	{
		scanf("%d", &excGrade); //Scanner
		hwSum += excGrade; //Summerise all the grades
	}
	switch (numOfHw)
	{
		case 0: //Case 0 to case 4 are total failure
		case 1:
		case 2:
		case 3:
		case 4:
		{
			grade = 0;
			break;
		}
		case 5: //Case 5 for 5 homework done and calculating total grade
		{
			grade = ((0.8 * exam) + (0.2 * (hwSum/numOfHw)));
			break;
		}
		case 6: //Case 6 for 6 homework done and calculating total grade
		{
			grade = ((0.6 * exam) + (0.4 * (hwSum/numOfHw)));
			break;
		}
	}
	printf("%.1f", grade); //Printing total final grade
}
