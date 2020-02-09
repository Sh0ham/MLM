#include <stdio.h>
#define n 9

void getID (char id[]); //Declaring functions
int isValid (char id[]);

int main()
{
  char id[n];
  printf("Please enter your ID: "); //Asking the user for ID input
  getID(id); //Calling the function
  (isValid(id) == 1) ? printf("Correct ID\n") : printf("Incorrect ID\n"); //Printing ID status
  return 0;
}
void getID (char id[]) //Reciving ID function
{
  int itt;
  for (itt = 0; itt < n; itt++) //Getting the  digits from user loop
  {
    scanf("%c", &id[itt]);
    if (id[itt] < '0' || id[itt] > '9') //Wrong input condition
    {
      itt = 0; //Setting the loop to start over
      printf("Wrong input, please enter your ID correctly: "); //Printing error message
      rewind(stdin); //Clearing the input
    }
  }
}
int isValid (char id[]) //ID Checker function
{
  int balanceID[n] = {1,2,1,2,1,2,1,2,1}; //Balance array
  int itt, sum; //Function variables
  for (itt = 0; itt < n; itt++) //Calculating the balance loop for specific ID
  {
    balanceID[itt] = ((id[itt]-48) * balanceID[itt]); //Calculation
  }
  for (itt = 0; itt < n; itt++) //Summary the balance
  {
    if (balanceID[itt] > 9) //Fixing loop for balance numbers over 9
    {
      balanceID[itt] = ((balanceID[itt]%10) + (balanceID[itt]/10)); //Calculation
      sum += balanceID[itt];
    }
    else
    {
      sum += balanceID[itt];
    }
  }
  return (sum%10 == 0) ? 1 : 0; //Checking wether ID is real or fake
}
