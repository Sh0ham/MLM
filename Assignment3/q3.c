/***************************************************************************************
* ██████╗ ███████╗ ██████╗████████╗ █████╗ ███╗   ██╗ ██████╗ ██╗     ███████╗███████╗ *
* ██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗████╗  ██║██╔════╝ ██║     ██╔════╝██╔════╝ *
* ██████╔╝█████╗  ██║        ██║   ███████║██╔██╗ ██║██║  ███╗██║     █████╗  ███████╗ *
* ██╔══██╗██╔══╝  ██║        ██║   ██╔══██║██║╚██╗██║██║   ██║██║     ██╔══╝  ╚════██║ *
* ██║  ██║███████╗╚██████╗   ██║   ██║  ██║██║ ╚████║╚██████╔╝███████╗███████╗███████║ *
* ╚═╝  ╚═╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝╚══════╝╚══════╝ *
*               This program finds full ascii-rectangles on given matrix               *
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8
#define M 12

void printMat(char matrix[][M], int rows, int cols); //Function declaration
void countRectangles(char matrix[][M], int rows, int cols);
int rectangleChecker(char matrix[][M], char currentChar, int rows, int cols);

int main()
{
  char matrix[N][M] = {{'#','#','#','.','.','.','?','?','.','.','+','.'},
                       {'#','#','#','.','=','.','?','?','.','.','+','.'},
                       {'#','#','#','.','.','.','.','.','.','.','+','.'},
                       {'.','.','.','.','.','?','?','?','.','.','.','.'},
                       {'?','?','?','.','.','?','?','?','.','.','=','='},
                       {'?','.','?','.','.','.','.','.','.','.','=','='},
                       {'?','?','?','.','+','+','+','.','.','.','.','.'},
                       {'?','?','?','.','+','+','+','.','#','#','.','#'}};
  printMat(matrix, N, M); //Printing the matrix
  countRectangles(matrix, N, M); //Execute program
  return 0;
}

/*Function name: printMat
Input: Matrix with it's sizes of rows and cols
Output: None
Algorithm: Rurowsing on two for loops, printing each element*/
void printMat(char matrix[][M], int rows, int cols)
{
  int itt, jtt, ktt; //Function variables
  printf("\n\t\t      ##     ##    ###  ######## ########  #### ##     ##\n");
  printf("\t\t      ###   ###   ## ##    ##    ##     ##  ##   ##   ##\n");
  printf("\t\t      #### ####  ##   ##   ##    ##     ##  ##    ## ##\n");
  printf("\t\t      ## ### ## ##     ##  ##    ########   ##     ###\n");
  printf("\t\t      ##     ## #########  ##    ##   ##    ##    ## ##\n");
  printf("\t\t      ##     ## ##     ##  ##    ##    ##   ##   ##   ##\n");
  printf("\t\t      ##     ## ##     ##  ##    ##     ## #### ##     ##\n\n");
  for (itt = 0; itt < rows; itt++) //Rows loop
  {
    printf(" ");
    for (ktt = 0; ktt < 94; ktt++)
    {
      printf("-"); //Printing first and inside matrix rows seperate lines
    }
    printf("\n");
    for (jtt = 0; jtt < cols; jtt++) //Cols loop
    {
      printf("|%4c\t", matrix[itt][jtt]); //Printing element
    }
    printf("|"); //Printing columns seperate lines
    printf("\n");
  }
  printf(" ");
  for (ktt = 0; ktt < 94; ktt++)
  {
    printf("-"); //Printing bottom seperate line
  }
  printf("\n");
  printf("\nBy given matrix, program computed:");
}
/*Function name: countRectangles
Input: Matris and string
Output: None
Algorithm: Running on each slot of the matrix, checking with helper function if given slot is part of rectangle and cound them all*/
void countRectangles(char matrix[][M], int rows, int cols)
{
  int itt, jtt, slot = 0, counter = 1; //Function variables
  char currentChar;
  char *str;
  str = (char *)malloc((rows*cols) * sizeof(char));
  if (!str) //Checking if memory was allocation succefully
  {
    printf("ERROR: Not enough memory!"); //If not, printing error message and quit the program
    exit(1);
  }
  for (itt = 0; itt < rows; itt++) //Running on 2 for loops, finding non-vacant slot
  {
    for (jtt = 0; jtt < cols; jtt++)
    {
      if (matrix[itt][jtt] != '.') //Non-vacant slot has been found
      {
        currentChar = matrix[itt][jtt]; //Setting current charcter to the slot charcter
        (rectangleChecker(matrix, currentChar, itt, jtt)) ? (str[slot++] = currentChar) : 0; //Checking if slot is part of rectangle
      }
    }
  }
  str[slot] = '\0'; //Fixing string starting point
  printf("\n"); //Nextline
  for (itt = 0; itt < strlen(str); itt++)
  {
    for (jtt = (itt+1); jtt < strlen(str); jtt++)
    {
      ((str[itt] == str[jtt]) && (str[itt] != '.')) ? ((counter++) && (str[jtt] = '.')) : 0;
    }
    (str[itt] != '.') ? (printf("Charcter (%c) has %d full rectangles\n", str[itt], counter)) : 0;
    counter = 1; //Fixing counter to next itteration
  }
  free(str); //Release memory allocated by the program
}
/*Function name: rectangleChecker
Input: Matrix with it's sizes of rows and cols and current charcter from countRectangles function
Output: 1 or 0, depends if given slot is part of rectangle
Algorithm: 2 While loops counting the rows and cols of the rectangle, than 2 for loops checking the inner of rectangle*/
int rectangleChecker(char matrix[][M], char currentChar, int rows, int cols)
{
	int itt = rows, jtt = cols, countCol = 0, countRow = 0, invalid = 0; //Function variables
	while ((matrix[itt][jtt] == currentChar) && (jtt < M)) //Counting number of columns has same charcter as current charcter
	{
		countCol++; //Updating column counter
		jtt++; //Updating index
	}
  jtt = cols; //Fixing the jtt variable to actual slot given
	while ((matrix[itt][jtt] == currentChar) && (itt < N)) //Counting number of rows has same charcter as current charcter
	{
		countRow++; //Updating row counter
		itt++; //Updating index
	}
	for (itt = rows; itt < (countRow+rows); itt++) //Running on the minor matrix, starting on the given slot
	{
		for (jtt = cols; jtt < (countCol+cols); jtt++)
		{
			(matrix[itt][jtt] != currentChar) ? invalid++ : 0; //One slot rectangle case
			if (((jtt-cols+1) == countCol) && (jtt+1 != M)) //Haven't reached last column of matrix
			{
				(matrix[itt][jtt+1] != '.') ? invalid++ : 0; //Updating invalid flag
			}
			else if (((itt-rows+1) == countRow) && (itt+1 != N)) //Haven't reached last row of matrix
			{
        (matrix[itt+1][jtt] != '.') ? invalid++ : 0; //Updating invalid flag
			}
			else if (jtt > 0) //Haven't reached last column of minor matrix
			{
				(matrix[itt][jtt-1] != '.') ? invalid++ : 0; //Updating invalid flag
			}
			else if (itt > 0) //Haven't reached last row of minor matrix
			{
				(matrix[itt-1][jtt] != '.') ? invalid++ : 0; //Updating invalid flag
			}
			else if ((itt > 0) && (jtt > 0)) //Haven't reached last row of minor matrix
			{
				(matrix[itt-1][jtt-1] != '.') ? invalid++ : 0; //Updating invalid flag
			}
			matrix[itt][jtt] = '.'; //Fixing all the slots of the rectangle to dot
		}
	}
	return ((invalid) ? 0 : 1); //Return one if passed all tests and it's full rectangle
}
