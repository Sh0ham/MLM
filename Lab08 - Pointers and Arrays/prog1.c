#include <stdio.h>   /*for printf and scanf function*/

void inputPoint(float *px, float *py);
void inputSeg(float *px1, float *py1, float *px2, float *py2);
void setMidSeg(float x1, float y1, float x2, float y2, float *pmx, float *pmy);

void main()
{
	float x1, y1, x2, y2, mx, my;
	printf("Enter a line segment in the plane, please.");
	inputSeg(&x1, &y1, &x2, &y2);
	setMidSeg(x1, y1, x2, y2, &mx, &my);
	printf("The midpoint of the line segment is(%f, %f)", mx, my);
}
/*
  Function name: inputPoint
  Input: 2 integers
  Output: None
  Algorithm: Setting 2 integers to 2 variables, represents a point on the plane
*/
void inputPoint(float *px, float *py)
{
	printf("Enter a point in the plane, please (x and y coords, repectively): ");
	scanf("%f %f", px, py);
}
/*
  Function name: inputSeg
  Input: 4 integers
  Output: None
  Algorithm: Setting 4 integers to 4 variables, represents a segment on the plane
*/
void inputSeg(float *px1, float *py1, float *px2, float *py2)
{
	inputPoint(px1, py1);
	inputPoint(px2, py2);
}
/*
  Function name: setMidSeg
  Input: 4 integers
  Output: 2 integers
  Algorithm: Calculation the mid point of the segment
*/
void setMidSeg(float x1, float y1, float x2, float y2, float *pmx, float *pmy)
{
	*pmx = ((x1 + x2) / 2);
	*pmy = ((y1 + y2) / 2);
}
