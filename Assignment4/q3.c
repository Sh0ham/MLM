/***************************************************************************************
*                ..          ..             ...                     .x+=:.        s    *
*              dF          dF           .zf"` `"tu                 z`    ^%      :8    *
*        u.   '88bu.      '88bu.       x88      '8N.                  .   <k    .88    *
*  ...ue888b  '*88888bu   '*88888bu    888k     d88&       u        .@8Ned8"   :888ooo *
*  888R Y888r   ^"*8888N    ^"*8888N   8888N.  @888F    us888u.   .@^%8888"  -*8888888 *
*  888R I888>  beWE "888L  beWE "888L  `88888 9888%  .@88 "8888" x88:  `)8b.   8888    *
*  888R I888>  888E  888E  888E  888E    %888 "88F   9888  9888  8888N=*8888   8888    *
*  888R I888>  888E  888E  888E  888E     8"   "*h=~ 9888  9888   %8"    R88   8888    *
* u8888cJ888   888E  888F  888E  888F   z8Weu        9888  9888    @8Wou 9%   .8888Lu= *
*  "*888*P"   .888N..888  .888N..888   ""88888i.   Z 9888  9888  .888888P`    ^%888*   *
*    'Y"       `"888*""    `"888*""   "   "8888888*  "888*""888" `   ^"F        'Y"    *
*                ""          ""            ^"**""    ^Y"   ^Y'                         *
****************************************************************************************/
#include <stdio.h>
#define N 6

int minOddLast(int *arr, int n); //Functions declaration
int minMatrixOdd(int arr[][N], int n);

int main()
{
  int matrix[N][N] = {{8,2,6,3,7,11},{22,12,5,21,21,33},{4,80,1,1,7,9},{120,12,2,10,15,27},{2,5,13,17,57,111},{54,14,3,111,111,113}}; //Matrix initialization
	printf("Matrix minimum odd integer is: %d\n", minMatrixOdd(matrix, N)); //Printing minimum value of given matrix
  return 0; //Exit program with no errors occurred
}

/*Function name: minOddLast
Input: Array with it's length
Output: Minimum odd value of given array
Algorithm: Checking if given array 2nd spot is odd; If so - return it's value. If not - checking if middle spot of the array is odd*/
int minOddLast(int *arr, int n)
{
	return (*(arr+1)%2 == 1) ? (*(arr+1)) : ((*(arr+n/2)%2 == 0) ? (minOddLast((arr+n/2), (n/2))) : (minOddLast((arr), (n/2+1))));
}
/*Function name: minMatrixOdd
Input: Matrix with it's sizes of rows\cols
Output: Minimum odd value of given matrix
Algorithm: Setting minMatrix to be the minimum of first row; if reached the last row - return  minMatrix.
           If not, call the function once again and compare it with the last minMatrix.*/
int minMatrixOdd(int arr[][N], int n)
{
  int minMatrix = minOddLast(arr[0], N), minHodor;
  if (n == 1)
  {
    return minMatrix;
  }
  minHodor = minMatrixOdd(&arr[1], n-1);
  return (minMatrix < minHodor) ? minMatrix : minHodor;
}
