/* 枚举 */

#include <stdio.h>

// 虽然枚举和结构、联合没有什么共同的地方，但是它们的声明方法很类似。
// 但是，与结构或联合的成员不同，枚举常量的名字必须不同于作用域范围内声明的其他标识符。
enum enum_colors { RED, BLUE, GREEN, PURPLE, BLACK, WHITE};

// 声明枚举变量c1, c2
enum enum_colors c1, c2;

// 无标记名，直接声明枚举变量s1,s2
enum {red, blue} s1, s2;

typedef enum {Red, Blue, Green} Colors;
// 定义枚举类型c3，c3的值应该是enum列表中的一个，默认enum对应的数值是从0开始，依次加1.
Colors c3;

// 枚举可以用宏定义替换，但是不推荐
#define Red 0
#define Blue 1
#define Green 2

typedef enum {FALSE, TRUE} Bool;
Bool b1;

// 修改枚举的默认数值
// 枚举作为整数
typedef enum { aRed = 2, aBlue = 4, aBlack = 6} AColors;

AColors c4;


int main()
{
    b1 = FALSE; // 0
    Bool b2 = TRUE; // 1
    // 给枚举类型变量c3赋值
    // 错误的写法：enum.Blue
    c3 = Blue;
    printf("%d\n", c3);

    c4 = aBlack;
    printf("%d\n", c4);
}
