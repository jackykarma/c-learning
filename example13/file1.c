#include <stdio.h>
#include "file1.h"

int sum(int a, int b)
{
   int sum = a + b;
   printf("sum=%d\n", sum);

   return sum;
}

float area(float r)
{
    float area = PIE * r * r;
    printf("area=%f\n", area);

    return area;
}
