// Name: pun.c
// Purpose: Print a bad pun
// Author: K. N. King

// 预处理指令
#include <stdio.h>

// 宏定义：此处宏定义用来定义一个常量，表示1分钟有60秒
#define SECONDS_ONE_MINUTE 60
// 可以定义为表达式计算出结果作为常量
#define SCALE_FACTOR (5.0f / 9.0f)

int main()
{
    // 打印
    printf("To C, or not to C: that is the question.\n");
    printf("How many seconds within a minute:%d\n", SECONDS_ONE_MINUTE);

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
