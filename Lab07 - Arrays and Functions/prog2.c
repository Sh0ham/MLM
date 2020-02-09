#include <stdio.h>

float avg (float run[]);

int main()
{
  float run[10];
  float average, sum;
  int itt, cnt = 0;
  printf("Enter times, please: ");
  for (itt = 0; itt < 10; itt++)
  {
    scanf("%f", &run[itt]);
  }
  average = avg(run);
  for (itt = 0; itt<10; itt++)
  {
    run[itt] < average ? cnt++ : 0;
  }
  printf("The number of runners, running below the average time is %d.", cnt);
  return 0;
}

float avg (float run[])
{
  int itt;
  float sum;
  for (itt = 0; itt<10; itt++)
  {
    sum += run[itt];
  }
  return (sum/10);
}
