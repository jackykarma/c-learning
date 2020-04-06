/* scanf函数进行格式化输入 */

#include <stdio.h>

// scanf函数也根据特定的格式读取输入
// scanf函数本质上是一种“模式匹配”函数，试图把输入的字符串与转换说明相匹配
int main()
{
    int i, j;
    float x, y;

    // 错误的写法，scanf需要知道输入的值所要写入的地址，而不是变量，一定记得加地址符号&
    // scanf("%d %d, %f %.2f", i, j, x, y);
    // 错误 %.2f并不能表示要求输入精度为2的浮点数
    // scanf("%d %d, %f %.2f", &i, &j, &x, &y);

    // 陷阱：
    // 1. 编译器无法检查出格式转换与参数数量或类型的不匹配 
    // 2. 符号&常常（但不总是）是需要的
    scanf("%d%d%f%f", &i, &j, &x, &y);

    // 用户输入何时算结束？
    // scanf函数如何界定多个参数的边界，例如i,j,x,y的取值在用户输入的字串中是如何分割与分配的？

    // 在寻找数的起始位置时，scanf函数会忽略空白字符（white-space character, 包括空格符、水平和垂直制表符
    // 换页符和换行符）, 因此，我们可以把数字放在同一行或者分散在几行内输入。
    
    // 在读取整数或浮点数时：scanf函数首先寻找正号或负号，然后读取数字直到一个非数字时才停止；浮点还需要寻找小数点
    // 或者指数字母e

    printf("user input result:i=%d,j=%d,x=%f,y=%f\n", i, j, x, y);


    // 虽然scanf与printf函数调用看起来很相似，但两个函数之间有很大的差异。
    // 情景：printf打印提示，scanf输入
    int age;

    printf("Please input your age:");
    scanf("%d", &age);
    printf("Your age is:%d\n", age);

    return 0;
}
