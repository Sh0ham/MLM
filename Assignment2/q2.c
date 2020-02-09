#include <stdio.h>
#define n 100

void postfix (int exercise[], int numOfOps); //Function decleration

int main()
{
  int exercise[n]; //Array decleration with n slots (n=100)
  int numOfOps; //Number of operands
  printf("Enter number of operands (2-100):"); //Asking user for operands amount
  scanf("%d", &numOfOps); //Getting user's amount
  if (numOfOps > 100 || numOfOps < 2) //If number of operands is not calculateable or to big
  {
    printf("Wrong number of operands\n"); //Print error and starting over
    main();
  }
  else //Good amount of operands
  {
    postfix(exercise ,numOfOps); //Calling the function
  }
  return 0;
}

void postfix(int exercise[], int numOfOps) //Function
{
  int itt, operand; //Deleration of function variables
  char operator; //Deleration of operator
  for (itt = 0; itt < numOfOps; itt++) //Reciving the operands from user loop
  {
    printf("Enter operand (%d):", (itt));
    scanf("%d", &exercise[itt]);
  }
  int result = exercise[numOfOps-1]; //Pivot variable, set to be last operand
  for (itt = (numOfOps-1); itt >= 1; itt--) //Calculation loop
  {
    rewind(stdin); //Fixing the enter charcter
    printf("Enter operator (+ - *):");
    scanf("%c", &operator);
    switch (operator) //Different operators methods
    {
      case '+': //Adding methond
      {
        result += exercise[itt-1];
        break;
      }
      case '*': //Multiplication method
      {
        result *= exercise[itt-1];
        break;
      }
      case '-': //Minus method
      {
        result = exercise[itt-1] - result;
        break;
      }
      default: //Wrong operand
      {
        printf("Press only + - *\n"); //Print error
        itt++; //Adding one more itteration for the loop
        break;
      }
    }
  }
  printf("Result: %d\n", result); //Printing result
}
