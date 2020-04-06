/* 类型定义 */

#include <stdio.h>

// 第一种方式：因此可以使用BOOL定义声明变量，本质就是int
#define BOOL int

// 第二种方式：更好的方式用typedef关键字
typedef int Bool;
#define TRUE 1;
#define FALSE 0;

int main(void)
{
    Bool flag;
    BOOL flag2;

    // C语言没有true和false
    flag = TRUE;
    flag2 = FALSE;

    printf("flag=%d, flag2=%d\n", flag, flag2);

    int x = sizeof(flag);
    int y = sizeof(float);
    int z = sizeof(flag + flag2);

    printf("x=%d, y=%d, z=%d\n", x, y, z);

    return 0;
}
