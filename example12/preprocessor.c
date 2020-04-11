/* 预处理器 */

// 1. 宏定义
// 2. 条件编译

// C程序->预处理器->修改后的C程序->编译器编译->目标代码->链接为可执行文件

#include <stdio.h>

/*********************************************************
 * 宏定义
 *
 * *******************************************************/
// 格式：#define 标志符 替换列表
// 格式：#define 标志符(参数1，参数2，....) 替换列表

// 简单的宏
#define PIE 3.14
// 简单的宏定义：多行表达式
#define EXPRE printf("This is a new world!"); \
	printf("I'm not sure"); 
// 表示硬盘的容量：宏定义是一个计算表达式
#define DISK_CAPACITY (SIDES * \
		TRACKS_PER_SIDE * \
		SECTORS_PER_TRACK * \
		BYTES_PER_SECTOR)

#define BEGIN {
#define END   }
#define LOOP for (;;) // 无限循环
#define BOOL int
// 控制条件编译
#define DEBUG
// 删除宏定义
#undef DEBUG

// 2.带参数的宏
// - 若宏的替换列表中有运算符，那么始终要将整个替换列表放在括号中
// - 若宏有参数，每个参数每次在替换列表中出现时都要放在圆括号中
#define MAX(x,y) ((x) > (y) ? (x) : (y)) 

// 3.#运算符
// #运算符通知预处理器根据宏定义的参数创建一个字符串字面量。
// 下面#n表示将参数n替换为一个字符串自字面量
#define PRINT_INT(n) printf(#n " = %d\n", n)

// 4.##运算符
// ##运算符可以将两个记号（如标志符）"粘合" 在一起，成为一个记号。称为“记号粘合”
// 如下就是讲i的与n这个参数值以字符串的形式拼接在一起变为in(其中n是传入的参数值)
// 这个安卓Binder接口C层代码也用到此运算符
#define MK_ID(n) i##n

// 5.在宏的替换列表中包含对其他宏的调用
#define PI 3.14149
#define TWO_PI (2*PI)

// 6.创建较长的宏
// 逗号运算符: 依次执行多个表达式，在其他代码也通用。
// gets总是报segment 11错误，因此采用scanf替代
#define ECHO(s) ( gets(s), puts(s) )
// 也可以复合语句替代, 分号; 虽然可以用，但是在if语句中会编译错误，因此不要使用❌
#define ECHO2(s) { gets(s); puts(s); }

// 宏需要包含一些列的语句，而不仅仅是一系列的语句时。逗号运算符无法解决问题，需要使用do...while(0)
// while(0) 表示此语句只执行一次。这是对上面复合语句的改进处理。
#define ECHO3(s)     \
	do {         \
	  gets(s);   \
	  puts(s);   \
	} while (0)

// 7.预定义的宏
// __LINE__ 被编译的文件中的行号
// __FILE__ 被编译的文件名
// __DATE__ 编译的日期
// __TIME__ 编译的时间
// __STDC__ 如果编译器复合C标准(C89或C99)，那么值为1
//
// C99中新增加的预定义宏
// __STDC_HOSTED__
// __STDC_VERSION__
// __STDC_IEC_559__
// __STDC_IEC_559_COMPLEX__
// __STDC_ISO_10646__

// 8.空的宏参数：参数省略
#define ADD(x,y) (x+y)
// 下面为何报错，参数不是都要用括号吗？
// #define ADD(x,y) ((x)+(y))
// 对于没有传的参数，使用空字符""替代。
#define JOIN(x,y,z) x##y##z

// 9.参数可变的宏
// C89是固定，C99是可变
// 宏具有可变参数个数的主要原因是：它可以将参数传递给具有可变参数个数的函数，如printf和scanf
// __VA_ARGS__是一个专用的标识符，只能出现在具有可变参数个数的宏的替换列表中，代表所有与省略号相对应的参数。
// 至少有一个与省略号相对应的参数，但该参数可以为空。
#define TEST(condition, ...) ((condition)? \
		printf("Passed test: %s\n", #condition): \
		printf(__VA_ARGS__))

// __func__标识符，可以获取函数名称


/****************************************************************************************************
 *
 * 条件编译:#if #elif #else #endif
 * 条件编译是指：根据预处理器所执行的测试结果来包含或排除程序的片段
 * #if DEBUG: #if指令会测试DEBUG的值，由于DEBUG不是0，处理器就会处理，如果DEBUG是0就不会处理。
 *
 * #if defined(DEBUG) 如果DEBUG是一个定义过的宏就返回1，否则返回0（PS:只要定义过就可以,与#if不同）  
 * #ifdef DEBUG / ifndef DEBUG : 如果定义了、如果没有定义
 *
 * #ifdef DEBUG 等价于 #if defined(DEBUG)
 * #ifndef DEBUG 等价于 #if !defined(DEBUG)
 *
 * *************************************************************************************************/
#define DEBUG_TEST 1
#undef DEBUG_TEST
#define TEST1 1
#undef TEST1
#define TEST2 -10
#define TEST3 1

#if TEST1
void test()
{
    printf("test condition 1");
}
#elif TEST2
void test2()
{
    printf("test condition 2");
}
#elif TEST3
void test3()
{
    printf("test condition 3");
}
#else
void test()
{
    printf("test condition 1");
}
#endif

/***********************************************************************************************
 *
 * 其他指令:#line #progma #error
 *
 * *********************************************************************************************/


int main(void)
{
    int max = MAX(10,20); 
    PRINT_INT(max);
    PRINT_INT(10);

    // 定义int变量i1/i2/i3,其中i3 = 90
    int MK_ID(1), MK_ID(2), MK_ID(3) = 90;
    PRINT_INT(MK_ID(3));

    char str[20];
    // 用指针会引起段错误, 因为编译器不知道是一个数组长度
    // char *str;
    // 先定义数组，再这样赋值给指针是可以的。
    char *strp = str;
    //scanf("%s", strp);
    //printf("%s\n", strp);
    // 替换为(scanf(s), puts(s));
    ECHO(str);
    // 一般运行正常，但是在if语句中运行有问题
    ECHO2(strp);

    // 下面语句会出现编译错误
    // if (1)
    //    ECHO2(strp);
    // else
    //	 gets(strp);

    // 宏需要包含一系列的语句而不是一些列的表达式 
    ECHO3(strp); 

    // 空的宏参数是如何处理的
    // 结果等于10; sum = (+10)
    int sum = ADD(,10); 
    PRINT_INT(sum);

#ifdef TEST1
    // int abc, ab, b, ac
    // 对于没有传的参数，使用空字符""替代。
    int JOIN(a,b,c), JOIN(a,b,), JOIN(,b,), JOIN(a,,c);
#endif

#if defined(TEST3)
    // TEST宏定义需要两个参数：1个是condition条件表达式；另外一个是可变参数
    int voltage = 10;
    int max_voltage = 100;
    TEST(voltage <= max_voltage, "Voltage %d exceeds %d\n", voltage, max_voltage);

    voltage = 200;
    TEST(voltage <= max_voltage, "Voltage %d exceeds %d\n", voltage, max_voltage);
#endif

    printf("[func]=%s\n", __func__);
    return 0;
}
