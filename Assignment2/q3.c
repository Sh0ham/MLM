#include <stdio.h>
#define n 6 //Constant list max length

int add_element_to_start(int list[], int listLength, int number); //Declaring functions
int add_element_to_end(int list[], int listLength, int number);
int delete_element_by_value(int list[], int listLength, int number);
void replace_element_by_value(int list[], int listLength, int oldNum, int newNum);
void print_list(int list[], int listLength);

int main()
{
  int list[n] = {0}; //Initialization list with zeros
  int func = 0, listLength = 0, number; //Program variables
  printf("Greetings!\nThis program's functions are numbered from (1) to (6):\n"); //Inform user with instructions
  printf("1.Add a positive number to start of the list\n");
  printf("2.Add a positive number to end of the list\n");
  printf("3.Delete number(s) from the list\n");
  printf("4.Replace number(s) by another number\n");
  printf("5.Print your list\n");
  printf("6.Exit the program\n\n");
  while (func != 6) //Endless loop with exit function
  {
    printf("Enter function number, please: "); //Asking the user for instructions
    scanf("%d", &func); //Getting user's functin number
    switch (func)
    {
      case 1: //Adding number to start of the list function call
      {
        printf("Enter number, please: ");
        scanf("%d", &number);
        listLength = add_element_to_start(list, listLength, number);
        (listLength == (-1)) ? (listLength = 6) : 0;
        print_list(list, listLength);
        break;
      }
      case 2: //Adding number to end of the list function call
      {
        printf("Enter number, please: ");
        scanf("%d", &number);
        listLength = add_element_to_end(list, listLength, number);
        (listLength == (-1)) ? (listLength = 6) : 0;
        print_list(list, listLength);
        break;
      }
      case 3: //Delete number from the list function call
      {
        int number;
        printf("Enter number, please: ");
        scanf("%d", &number);
        listLength = delete_element_by_value(list, listLength, number);
        print_list(list, listLength);
        break;
      }
      case 4: //Replace number by another number function call
      {
        int oldNum, newNum;
        printf("Enter the number you desire to replace: ");
        scanf("%d", &oldNum);
        printf("Enter your new number: ");
        scanf("%d", &newNum);
        replace_element_by_value(list, listLength, oldNum, newNum);
        print_list(list, listLength);
        break;
      }
      case 5: //Printing list function call
      {
        print_list(list, listLength);
        break;
      }
      case 6: //Exit function
      {
        func = 6;
        printf("Bye!\n");
        break;
      }
      default: //Error printer
      {
        printf("ERROR: Wrong function number!\n");
        break;
      }
    }
  }
  return 0;
}
int add_element_to_start(int list[], int listLength, int number)
{
  int slots = 0, itt; //Function variables
  for (itt = 0; itt < n; itt++) //Checking if list has space for new number
  {
    (list[itt] == 0) ? slots++ : 0;
  }
  if (slots == 0) //List is full
  {
    printf("ERROR: The number you asked to add wasn't added, as your list is full!\n");
    return (-1);
  }
  if (number < 1)
  {
    printf("ERROR: Only positive numbers are allowed, buddy!\n");
    return listLength;
  }
  else //List isn't full
  {
    for (itt = (n-slots-1); itt >= 0; itt--)
    {
      list[itt+1] = list[itt]; //Moving all the list one step forward
    }
    list[0] = number; //Inserting the new number to start of the list
    return (++listLength); //Calculating up to date length of list
  }
}
int add_element_to_end(int list[], int listLength, int number)
{
  int slots = 0, itt; //Function variables
  for (itt = 0; itt < n; itt++) //Checking if list has space for new number
  {
    (list[itt] == 0) ? slots++ : 0;
  }
  if (slots == 0) //List is full
  {
    printf("ERROR: The number you asked to add wasn't added, as your list is full!\n");
    return (-1);
  }
  if (number < 1)
  {
    printf("ERROR: Only positive numbers are allowed, buddy!\n");
    return listLength;
  }
  else //List isn't full
  {
    list[n-slots] = number; //Inserting the new number to the first avaiable spot
    return (++listLength); //Calculating up to date length of list
  }
}
int delete_element_by_value(int list[], int listLength, int number)
{
  int slots = 0, helper = 0, itt; //Function variables
  for (itt = 0; itt < listLength; itt++) //Replacing given number by zero & count them
  {
    (list[itt] == number) ? ((list[itt] = 0) || (slots++)) : 0;
  }
  for (itt = 0; itt < n; itt++) //Moving all natural numbers
  {
    (list[itt] != 0) ? list[helper++] = list[itt] : 0;
  }
  for (itt = helper; itt < n; itt++) //Inserting zero where should be
  {
    list[itt] = 0;
  }
  return (listLength - slots); //Calculating up to date length of list
}
void replace_element_by_value(int list[], int listLength, int oldNum, int newNum)
{
  int itt, counter = 0;
  for (itt = 0; itt < listLength; itt++)
  {
    (list[itt] == oldNum) ? counter++ : 0;
  }
  (counter == 0) ? printf("The number you wished to replace dosen't appear on your list, buddy!\n") : 0;
  for (itt = 0; itt < listLength; itt++) //Replacing loop
  {
    (list[itt] == oldNum) ? (list[itt] = newNum) : 0; //Works only on given old number
  }
}
void print_list(int list[], int listLength)
{
  int itt;
  if (listLength == 0) //Empty list
  {
    printf("Your list is empty, buddy!"); //Error message
  }
  else //List has at least one number
  {
    printf("Your up to date list includes the number(s): ");
    for (itt = 0; itt < listLength; itt++) //Printing every number on the list by  loop
    {
      printf("%d ", list[itt]);
    }
  }
  printf("\n");
}
