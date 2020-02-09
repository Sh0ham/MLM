#include <stdio.h>
#include <stdlib.h>

int main()
{
    int currentDay, currentMonth, currentDayNum; //First date variables given by user
    int nextDay, nextMonth, nextDayNum = 0; //Second date variables given by user
    int daysInMonth, year, daysCounter = 0; //Program variables
    scanf("%d %d %d %d %d", &currentDay, &currentMonth, &currentDayNum, &nextDay, &nextMonth); //Getting input by user
    year = (((nextMonth < currentMonth) || ((nextMonth == currentMonth) && (nextDay < currentDay))) ? 2020 : 2019); //Ternary condition for year checking
    if ((currentDay < 1) || (currentDay > 31) || (currentMonth < 1) || (currentMonth > 12) || (currentDayNum < 1) || (currentDayNum > 7) || (nextDay < 1) || (nextDay > 31) ||
				(nextMonth < 1) || (nextMonth > 12) || ((currentMonth == 2) && (currentDay > 28)) || ((year == 2019) && (nextMonth == 2) && (nextDay > 28)) ||
			  ((year == 2020) && (nextMonth == 2) && (nextDay > 29)) || (((currentMonth <= 7 && currentMonth%2 == 0) || (currentMonth > 7 && currentMonth%2 == 1)) && currentDay > 30) ||
				(((nextMonth <= 7 && nextMonth%2 == 0) || (nextMonth > 7 && nextMonth%2 == 1)) && nextDay > 30)) //Checking dates
    {
        printf("Illegal input"); //Dates given are wrong by some parameter
    }

	else //Given dates passed the logic test
	{
		(year == 2020) ? nextMonth += 12 : 0; //Increasing the distance of months to next year if birthday  is on 2020
		for (currentMonth; currentMonth < nextMonth; currentMonth++) //Reminder counting loop
		{
			if ((currentMonth == 2) || (currentMonth == 14)) //February condition
			{
				daysInMonth = (((year%4 == 0) && (currentMonth == 14)) ? 29 : 28);
			}
			else if ((currentMonth > 12 && currentMonth <= 19 && currentMonth%2 == 1) || (currentMonth > 19 && currentMonth%2 == 0) ||
							 (currentMonth <= 7 && currentMonth%2 == 1) || (currentMonth > 7 && currentMonth <= 12 && currentMonth%2 == 0)) //31 Days month condition
			{
				daysInMonth = 31;
			}
			else if ((currentMonth > 12 && currentMonth <= 19 && currentMonth%2 == 0) || (currentMonth > 19 && currentMonth%2 == 1) ||
							 (currentMonth <= 7 && currentMonth%2 == 0) || (currentMonth > 7 && currentMonth <= 12 && currentMonth%2 == 1)) //30 Days month condition
			{
				daysInMonth = 30;
			}
			daysCounter += (daysInMonth%7); //Reminder counter for each month
		}
		if (nextDay != currentDay) //Checking if the  days of the months are different
		{
			switch (daysCounter%7) //Checking for the reminder type
			{
				case 0:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 1:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 1))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 1) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 2:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 2))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 2) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 3:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 3))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 3) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 4:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 4))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 4) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 5:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 5))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 5) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
				case 6:
				{
					if (nextDay > currentDay)
					{
						nextDayNum = ((nextDay - currentDay) + (currentDayNum + 6))%7;
						break;
					}
					else if (currentDay > nextDay)
					{
						nextDayNum = (abs((currentDayNum + 6) - (abs((nextDay - currentDay)%7))))%7;
						break;
					}
				}
			}
		}
		else if (nextDay == currentDay) //Calculate the day if it has same day of month
		{
			nextDayNum = (currentDayNum + daysCounter)%7;
		}
		else if ((currentMonth == nextMonth) && (year == 2019)) //Calculate the day if today's month is the month
		{
			nextDayNum = (nextDay - currentDay + currentDayNum)%7;
		}
		if (nextDayNum == 0) //Fixing Saturday
		{
			nextDayNum = 7;
		}
		printf("%d", nextDayNum); //Printing result
	}
}
