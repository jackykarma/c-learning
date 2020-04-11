/* C语言程序结构 */

// C语言程序构成的基本元素有：
// 1. 预处理命令：如#include 、#define
// 2. 类型定义：typeof 关键字
// 3. 外部变量声明：声明在所有函数体之外的变量
// 4. 函数原型：函数声明
// 5. 函数定义：函数实现 (局部变量定义)


// C99标准建议的编排顺序
// #include命令
// #define指令
// 类型定义typeof
// 外部变量的声明
// 除main函数之外的函数的原型
// main函数的定义
// 其他函数的定义


// 注释的建议：
// 每个函数定以前放盒型注释可以给出：函数名、描述函数的目的、讨论每个形式参数的含义、描述返回值并罗列所有的副作用（如修改了外部变量的值）


// 下面是一个demo示范


#include <stdio.h>

#define PIE 3.14
#define TRUE 1
#define FALSE 0

typedef float FLOAT;
typedef int BOOL;

// 外部变量
int ex_var = 50;

/* prototypes 函数原型 */
FLOAT cal_circle_area(FLOAT r);

int main(void)
{
    // 局部变量
    FLOAT r = 35.8f;
    // 静态局部变量
    static FLOAT area;
    // 不可以直接写：static FLOAT area = cal_circle_area(r);
    area = cal_circle_area(r); 
    printf("circle ared = %f\n", area); 
    return 0;
}

/*****************************************************
 * cal_circle_area: 计算以特定尺寸为半径的圆形面积
 *
 * ***************************************************/
FLOAT cal_circle_area(FLOAT r)
{
   return PIE * r * r;
}
