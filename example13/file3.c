#include <stdio.h>

#include "file3.h"

// 使用外部共享变量，在file2.h中定义
extern float exfloat;

int max_int(int x, int y)
{
   exfloat = 35.0f;
   int max = x > y ? (x+exfloat) : y;
   printf("max:%d\n", max);

   return max;
}
