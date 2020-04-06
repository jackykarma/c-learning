/* 格式化输出函数:printf */
/* printf(格式串, 表达式1, 表达式2, ...) */

#include <stdio.h>

int main()
{
    int i, j;
    float x, y;

    i = 10;
    j = 20;
    x = 15.32f;
    y = 5527.005f;

    printf("i=%d, j=%d, x=%f, y=%.2f, x+y=%f, i+j=%d, i+x=%f\n", i, j, x, y, x + y, i + j, i + x);
    
    // 转换说明
    // 格式：%m.pX或%-m.pX(其中m和p都是整数常量，而X是字幕。m和p都是可选的，m和p省略时，小数点也不写)
    // m表示minimum field width最小字段宽度, -m导致左对齐，m是右对齐
    // p表示precision精度
    int k = 40;
    float m = 839.21f;

    // 转义序列：\n换行 \a警报符 \t水平制表符 \b回退符
    // 特殊符号转义: "\"" "\\"
    printf("|%d|%5d|%-5d|%5.3d|\n", k, k, k, k);
    printf("|%10.3f|%10.3e|%-10g|%f|\n", m, m, m, m);

    return 0;
}
