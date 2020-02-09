#include <stdio.h>   /*for printf and scanf function*/

int inputThree(int *x, int *y, int *z); //Declaring functions
void sortTwo(int *num1, int *num2);
void sortThree(int *x, int *y, int *z);


void main()
{
  int x, y, z, boolean = 1; //Declaring program variables
  while (boolean) //Boolean condition in while
  {
    boolean = inputThree(&x, &y, &z); //Setting the boolean condition
    if (boolean) //Checking the input
    {
      sortThree(&x, &y, &z); //Rearrange them with sortThree function
      printf("%d %d %d\n\n", x, y, z); //Printing the numbers after sorting them
    }
  }
  printf("Finish!");
}
/*
  Function name: inputThree
  Input: 3 integers
  Output: 1 or 0
  Algorithm: Returning 0 if and only if all 3 integers are zeros
*/
int inputThree(int *x, int *y, int *z)
{
  printf("Enter 3 integers, please: ");
  scanf("%d %d %d", x, y, z);
  return ((*x == 0 && *y == 0 && *z == 0) ? 0 : 1);
}
/*
  Function name: sortTwo
  Input: 2 integers
  Output: None
  Algorithm: Switching the value of 2 integers if and only if the first is bigger
*/
void sortTwo(int *num1, int *num2)
{
  int numHolder; //Declaring function variables
  if (*num1 > *num2) //Checking if first number is greater than second
  {
    numHolder = *num2;
    *num2 = *num1;
    *num1 = numHolder;
  }
}
/*
  Function name: sortThree
  Input: 3 integers
  Output: None
  Algorithm: Using sortTwo function 3 times, on each
*/
void sortThree(int *x, int *y, int *z)
{
  sortTwo(&*x, &*y);
  sortTwo(&*x, &*z);
  sortTwo(&*y, &*z);
}
