#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sortNumbersInString(char *str); //Function declaration

int main()
{
	char str[] = {"4323442546465 57653234 8777669999999 12334555 2324"}; //Program variables
	printf("%s", sortNumbersInString(str));
	return 0;
}

/*Function name: sortNumbersInString
Input: Pointer to first address of the string
Output: Ordered numbers string
Algorithm: Using pointer to first slot of each number given on the string, starting right after a spcae bar charcter;
	   Converting the number from charcters to unsigned long long int and storing it in new integer array;
	   Sorting using bubble sort the integers array and than converting each slot of the array back to the main string*/
char* sortNumbersInString(char *str)
{
	char *strHodor = (char *)malloc((strlen(str)+1) * sizeof(char)); //Function variable
	char *currentNum;
	int itt, jtt, flag = 0;
	unsigned long long int *intHodor;
	unsigned long long int numHodor;
	if (!strHodor) //strHodor couldn't allocated memory
	{
		printf("Low memory, couldn't finish program correctly\n"); //Printing error
		exit(1); //Quiting program with error code (1);
	}
	for (itt = 0; itt < strlen(str); itt++) //Running on given string, finding how many spaces are inside
	{
		(str[itt] == ' ') ? flag++ : 0; //Each space raise the flag, defining how  many numbers inside the string
	}
	intHodor = (unsigned long long int *)malloc((flag+1) * sizeof(unsigned long long int)); //Numbers array memory allocation
	if (!intHodor) //intHodor couldn't allocated memory
	{
		printf("Low memory, couldn't finish program correctly\n"); //Printing error
		exit(1); //Quiting program with error code (1);
	}
	strcpy(strHodor,str); //Copying the original string to temp string
	str[0] = '\0'; //Fixing user's string to hold nothing untill program paste numbers back ordered
	itt = 0; //Resetting itt variable to use within the while loop
	currentNum = strtok(strHodor," "); //Splitting first number from the string
	while (currentNum != NULL) //strHodor string isn't empty yet
  {
    intHodor[itt] = strtoull(currentNum, NULL, 10); //Storing the converted number into the array
    currentNum = strtok(NULL," "); //Tearing apart the next number
		itt++; //Updating the index
  }
	for (itt = 0; itt < flag+1; itt++) //Bubble sort loop
	{
		for (jtt = 0; jtt < flag+1; jtt++) //Running on each element comparing each value
		{
			if (intHodor[jtt] > intHodor[itt])
			{
				numHodor = intHodor[itt]; //Temporary value holder
				intHodor[itt] = intHodor[jtt]; //Swaping
				intHodor[jtt] = numHodor; //Setting the temporary value back
			}
		}
	}
	currentNum = str; //Setting the currentNum pointer to the start of the string
	for (itt = 0; itt < flag+1; itt++) //Running on the integers array with for loop
	{
		sprintf(currentNum += strlen(currentNum), "%llu", intHodor[itt]); //Copying back the reordered numbers transfering it back to charcters
		strcat(str, " ");
	}
	str[strlen(str)-1] = '\0'; //Setting ending point to the string
	free(strHodor); //Realse the memory allocated by function
	free(intHodor);
	return str;
}
