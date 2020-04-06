/* 表达式 */

#include <stdio.h>

int main()
{
    // 赋值运算符
    // 赋值运算符要求它的左操作数必须是左值lvalue。左值：表示存储在计算机内存中的对象，而不是常量或计算的结果
    // 错误：
    // 12 = i;
    // i + j = 9;
    // -i = j;

    int i = 10;
    long j = 600 + 30000;
    float f = 56.07f + 89.32f/80.0f;

    printf("i=%d, j=%ld, f=%f\n", i, j, f);

    // 自增自减
    i++;
    printf("i=%d\n", i);
    --i;
    printf("i=%d\n", i);

    // 复合赋值
    int k = 30;
    k += i;
    printf("k=%d\n", k);

    // 除法/取模（取余）
    int a = 10;
    int b = 3;
    float c = 3.0;
    // 整型除整型结果是整型
    printf("a/b=%d\n", a/b);
    // 整型处于浮点结果是浮点类型
    printf("a/c=%f\n", a/c);
}
