#include <stdio.h>

int main()
{
  int counter[10] = {0};
  int digit, itt, max = counter[0];
  long long num;
  printf("Enter an integer number, please: ");
  scanf("%lld", &num);
  if (num == 0)
  {
    printf("The digit 0 appears 1 times.\nThe most frequent digit/s is/are: %lld ", num);
  }
  else
  {
    if (num < 0)
    {
      num *= (-1);
    }
    while (num)
    {
      digit = num%10;
      counter[digit]++;
      num /= 10;
    }
    for (itt = 0; itt <= 9; itt++)
    {
      if (counter[itt] > 0)
      {
        printf("The digit %d appears %d times.\n", (itt), counter[itt]);
      }
      if (counter[itt] > max)
      {
        max = counter[itt];
      }
    }
    printf("The most frequent digit/s is/are: ");
    for (itt = 0; itt <= 9; itt++)
    {
      if (counter[itt] == max)
      {
        printf("%d ", itt);
      }
    }
  }
}
