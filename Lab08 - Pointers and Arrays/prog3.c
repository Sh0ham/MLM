#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void getArr(int arr[]); //Getting the array from the user function
int getMax(); //Getting max value from user function
void fillRand(int arr[], int maxValue); //Filling an array with random integers function
int fillArr(int arr1[], int arr2[], int arr3[]); //Filling an array with unique integers
void printArr(int arr[], int arrLength); //Priting the array function

void main()
{
  int arr1[N], arr2[N], arr3[N] = {0};
  int maxValue, arrLength = 0;
  getArr(arr1);
  maxValue = getMax();
  fillRand(arr2, maxValue);
  arrLength = fillArr(arr1, arr2, arr3);
  printf("Array 1: ");
  printArr(arr1, N);
  printf("Array 2: ");
  printArr(arr2, N);
  if (arrLength != 0)
  {
    printf("Array 3: ");
    printArr(arr3, arrLength);
  }
  else
  {
    printf("No!!!");
  }
}
/*
  Function name: getArr
  Input: Array
  Output: Full array with integers
  Algorithm: Running on a "for" loop, inserting integer on each slot
*/
void getArr(int arr[])
{
  int itt;
  for (itt = 0; itt < N; itt++)
  {
    printf("Enter arr[%d]: ", itt);
    scanf("%d", &arr[itt]);
  }
}
/*
  Function name: getMax
  Input: None
  Output: User's integer
  Algorithm: Asking user for integer, everything greater than zero is acceptable;
             If user's input is not acceptable calling the function once more
*/
int getMax()
{
  int maxValue;
  printf("Enter max value greater than zero: ");
  scanf("%d", &maxValue);
  if (maxValue < 1)
  {
    getMax();
  }
  return maxValue;
}
/*
  Function name: fillRand
  Input: Array and integer
  Output: Array with random integers generated from (0,maxValue];
  Algorithm: Running on a "for" loop and inserting random integers to each slot of the array
*/
void fillRand(int arr[], int maxValue)
{
  int itt;
  srand(time(NULL));
  for (itt = 0; itt < N; itt++)
  {
    arr[itt] = rand()%maxValue+1;
  }
}
/*
  Function name: fillArr
  Input: 3 arrays
  Output: 1 integer represents length of array #3
  Algorithm: Running on array #1 and array #2, on two "for" loops.
             If a number from array #1 wasn't found on array #2 setting it to
             array #3 one time.
*/
int fillArr(int arr1[], int arr2[], int arr3[])
{
  int ittSt, ittNd, ittRd = 0, ittTh, flag = 0, counter = 0; //Function variables
  for (ittSt = 0; ittSt < N; ittSt++) //Outer itteration, running on first array
  {
    for (ittNd = 0; ittNd < N; ittNd++) //Inner itteration, running on second array
    {
      (arr1[ittSt] != arr2[ittNd]) ? counter++ : 0; //Comapring each element of first array with whole second array
    }
    if (counter == N) //If first array is completly different from second array
    {
      for (ittTh = 0; ittTh < N; ittTh++) //Running on third array
      {
        (arr3[ittTh] == arr1[ittSt]) ? flag++ : 0; //Comparing third array elements with first one, validating only one time elemnt will get inside third array
      }
      (flag == 0) ? ((arr3[ittRd] = arr1[ittSt]) && (ittRd++)) : 0; //If nothing from first array has been found, implementing the elemnt to third array and count up the number of elements to print
    }
    counter = 0; //Zeroing variable for next itteration
    flag = 0; //Zeroing variable for next itteration
  }
  counter = 0; //Zeroing variable for next itteration
  for (ittSt = 0; ittSt < N; ittSt++) //Running on first array loop, checking number if was there any "zeros"
  {
    arr1[ittSt] == 0 ? counter++ : 0;
  }
  return ((counter != 0) ? (++ittRd) : (ittRd)); //Returning the length of array to print. if has been any zero on first array, will print one zero aswell
}
/*
  Function name: printArr
  Input: Array
  Output: Print the array on the screen
  Algorithm: Running on a "for" loop printing the array
*/
void printArr(int arr[], int arrLength)
{
  int itt;
  for (itt = 0; itt < arrLength; itt++)
  {
    printf("%d ", arr[itt]);
  }
  printf("\n");
}
