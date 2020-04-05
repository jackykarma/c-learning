// Name: pun.c
// Purpose: Print a bad pun
// Author: K. N. King

// 预处理指令
#include <stdio.h>

int main()
{
    // 打印
    printf("To C, or not to C: that is the question.\n");

    // 数组必须指定数组的size
    char name[20];
    char genre[6];
    int age;
    float anything;
    // 读入输入
    // 错误的写法scanf是读取输入，不能向console打印
    // scanf("Please input your name age genre:[%s] your age=[%d] your genre:[%s]", name, &age, genre);
    printf("Input name:");
    scanf("%s", name);
    printf("Input age:");
    scanf("%d", &age);
    printf("Input genre:");
    scanf("%s", genre);
    printf("Input any float:");
    scanf("%f", &anything);
    printf("name:%s, age=%d, genre=%s\n", name, age, genre);
    // 浮点数打印的精度是小数点后2位。%.nf格式（n是小数点后的位数：精度）
    printf("anything:%.2f\n", anything);
    return 0;
}
