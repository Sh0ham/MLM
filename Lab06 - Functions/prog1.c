#include <stdio.h>

void f(char c, int a);
int a,i,j,h;
char c;

void main()
{
  printf("Enter a character an integer, please: ");
  scanf("%c %d", &c, &a);
  f(c,a);
}

void f(char c, int a)
{
  h = a;
  for (i = 0; i<a; i++)
  {
    for (j = 0; j<h; j++)
    {
      printf("%c", c);
    }
    printf("\n");
    h--;
  }
}
