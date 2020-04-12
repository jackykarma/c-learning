#include <stdio.h>
#include "file2.h"

extern float exfloat;

float max_float(float x, float y)
{
    float max;
    max = x > y ? (x + exfloat) : y;
    PRINT_FLOAT(max);
    return max;
}
