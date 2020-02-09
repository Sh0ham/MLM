#include <stdio.h>
#include <stdlib.h>

int isPalindrom(int arr[], int n);

int main()
{
	int itt, *arr, length = 1; //Program variables
	printf("Enter a length of an array, please: ");
	while ((scanf("%d", &length) == 1) && (length > 0))
	{
		arr = (int *)malloc(length * sizeof(int));
		printf("Enter %d elements, please: ", length);
		for (itt = 0; itt < length; itt++)
		{
			scanf("%d", &arr[itt]);
		}
		(isPalindrom(arr, length) == 1) ? printf("The array is a palindrome.\n\n") : printf("The array is not a palindrome.\n\n");
		free(arr);
		printf("Enter length of an array, please: ");
	}
	printf("\n\nThank you for exploring palindrome array.\n");
	return 0;
}

/*Function name: isPalindrom
Input: Array with integers and it's length
Output: 1 or 0 depends on if the array given is palindrome
Algorithm: Comparing recursively each slot with it's symetric one from the end*/
int isPalindrom(int arr[], int length)
{
	return (length > 1) ? ((*arr == arr[length-1]) && (isPalindrom(arr+1,length-2))) : 1;
}
