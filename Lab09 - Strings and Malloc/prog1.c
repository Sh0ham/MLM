#include <stdio.h>
#include <stdlib.h>

int getArray(int flag);

int main()
{
	int flag; //Declaring program variable
	printf("Enter the number of integers: "); //Asking the user for array length
	scanf("%d", &flag); //Reciving user's choice
	while (flag) //Infinite loop, as long as there's natural number
	{
		flag = getArray(flag); //Setting the condition to be length of the array
	}
	printf("Bye Bye.."); //Exit program
}

/*Function name: getArray
Input: Integer, represents number of slots in array
Output: Integer, represents the slot of the max number given
Algorithm: For loop, running on the array and finds the max number*/
int getArray(int flag)
{   
	int max, spot, itt;
	int *intArray = (int *)malloc(flag * sizeof(int)); //Initializing array with length of "flag"
	if (intArray == NULL) //If wasn't able to locate memory, exit the program
	{
		printf("Not enough memory\n"); //Printing error
		exit(1); //Exit
	}
	max = intArray[0];
	printf("Enter %d integers: ", flag); //Asking the user for numbers
	 //Function variables. setting the max to first slot
	for (itt = 0; itt < flag; itt++) //For loop runnin on the array
	{
		scanf("%d", &intArray[itt]); //Getting the from the user
		if (max < intArray[itt]) //Checking if user gave new big number
		{
			max = intArray[itt]; //Setting the max to the biggest number
			spot = (itt+1); //Updating the slot of the biggest number
		}
	}
	printf("The maximum is at place %d\n", spot); //Printing the maximum number's slot
	free(intArray); //Realeasing the array memory
	printf("Enter the number of integers: "); //Asking the user once more for array length
	scanf("%d", &flag); //Reciving user's choice
	return flag; //Updating the flag condition and memory needs
}
