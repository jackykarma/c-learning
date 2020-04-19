/* 指向函数的指针 */

// 1. 函数名（不带括号）本身就是表示函数的入口地址，这与数组名类似
// 2. 指向函数的指针起始就是函数的入口地址

#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int *b);

int main(void)
{
    // 声明一个函数指针
    int (*funcptr)(int *, int *);
    // 这样声明更像是一个范围值是int指针的函数，因此必须用括号将声明符*和funcptr包在一起。
    // int *funcptr(int, int);

    // 函数指针指向的函数，他们的参数列表、返回值必须完全相同;也就是具备相同的签名。
    funcptr = sum;

    int m = 30;
    int n = 80;
    // funcptr 本质是一个函数指针，并非是一个函数，虽然C语言允许下面像使用函数一样去调用，但是编码推荐第二种方式，它
    // 精确的表明funcptr是一个函数指针，而并非是一个函数。
    int z = funcptr(&m, &n);
    int z2 = (*funcptr)(&m, &n);

    printf("sum z:%d, z2=%d\n", z, z2);

    return 0;
}

int sum(int *x, int *y)
{
    return *x +  *y;
}
