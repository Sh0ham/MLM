#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define G 9.81

float height (float v, int a, float t);
float horizontal (float v, int a, float t);
float deg2rad (int a);

int main()
{
  int a;
  float v, h = G, t;
  printf("Enter v <0.0-100.0> m/s and a <0-90 degrees>: ");
  while (G)
  {
    scanf("%f", &v);
    if (v < 0 || v > 100)
    {
      printf("Finish");
      return 0;
    }
    else
    {
      while (G)
      {
        if (v < 0 || v > 100)
        {
          printf("Finish");
          return 0;
        }
        scanf("%d", &a);
        if (a < 0 || a > 90)
        {
          printf("Finish");
          return 0;
        }
        else
        {
          for (t = 0.1;  h >= 0; t += 0.1)
          {
            h = height(v,a,t);
            printf("Time: %.1f....S=%.2f  H=%.2f\n", t, horizontal(v,a,t), height(v,a,t));
          }
          printf("\nFallen!");
        }
        printf("\nEnter velocity <0.0-100.0> m/s and angle <0-90 degrees>: ");
        scanf("%f", &v);
        h = G;
      }
    }
  }
}

float height (float v, int a, float t)
{
  return ((v * (sin(deg2rad(a))) * t) - ((G*t*t) / 2));
}
float horizontal (float v, int a, float t)
{
  return (v * cos(deg2rad(a)) * t);
}
float deg2rad (int a)
{
  return (a * PI / 180);
}
