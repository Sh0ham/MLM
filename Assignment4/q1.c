/**********************************************************************************
*  █████╗  ██████╗██╗  ██╗███████╗██████╗ ███╗   ███╗ █████╗ ███╗   ██╗███╗   ██╗ *
* ██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗████╗ ████║██╔══██╗████╗  ██║████╗  ██║ *
* ███████║██║     █████╔╝ █████╗  ██████╔╝██╔████╔██║███████║██╔██╗ ██║██╔██╗ ██║ *
* ██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗██║╚██╔╝██║██╔══██║██║╚██╗██║██║╚██╗██║ *
* ██║  ██║╚██████╗██║  ██╗███████╗██║  ██║██║ ╚═╝ ██║██║  ██║██║ ╚████║██║ ╚████║ *
* ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝ *
**********************************************************************************/
#include <stdio.h>

int Ackermann(int stNum, int ndNum); //Function declaration

int main()
{
	int stNum, ndNum; //Program variables
	printf("Please insert m and n: "); //Asking user for input
	scanf("%d %d", &stNum, &ndNum); //Getting user's input
	printf("Ackermann(%d, %d) = %d.\n", stNum, ndNum, Ackermann(stNum, ndNum)); //Printing calculated result for given input
  return 0;
}

/*Function name: Ackermann
Input: Two integers
Output: f(Ackermann)
Algorithm: Calculating Ackermann's number by calling it self*/
int Ackermann(int stNum, int ndNum)
{
	if (stNum == 0) //First number is zero condition
	{
		return (ndNum+1);
	}
	else if (ndNum == 0) //Second number is zero condition
	{
		return Ackermann(stNum-1,1);
	}
	else //Both numbers are greater than zero
	{
		return Ackermann(stNum-1,Ackermann(stNum,ndNum-1));
	}
}
