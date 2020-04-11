/* 字符串处理 */

// C语言中字符串变量起始就是字符数组，也就是char类型的数组
// 字符串字面量 "This is a world!"
// 字符串字面量中的转义序列 "Candy\nIs dandy\nBut liquor\nIs quicker.\n   --Ogden Nash\n"

#include <stdio.h>
#include <string.h>

/* prototypes */
void printf_and_puts();
void scanf_and_gets();
void strcpy_strcat_strcmp();

int main(void)
{
    printf("Candy\nIs dandy\nBut liquor\nIs quicker.\n"); 
    
    // 如何存储字符串字面量
    // 本质是字符数组，因此使用字符数组存储字符串字面量

    // 为何是7而不是6，因为字符串末尾会添加空字符'\0'以表示字符串的结束
    // 字符串变量
    char str1[7] = "Hi,Lee";
    printf("str1 = %s\n", str1);

    // 定义一个字符指针变量
    char *p;
    // 指针指向字符数组的首地址
    p = "abc";
    // 不能改变字符串字面量
    // *p = 'd';

    // 打印字符串时，%s表示传递字符数组的指针
    printf("p = %s\n", p);


    // 字符串字面量取下标 %c是字符
    printf("Get one character in a string:%c\n", "lee"[2]);

    printf_and_puts();
    scanf_and_gets();
    
    strcpy_strcat_strcmp();

    return 0;
}

/************************************************
 *
 * printf函数和puts函数进行字符串的读
 *
 ************************************************/
void printf_and_puts()
{
    char str[] = "Hello, This is michael!";

    printf("%s\n", str);
    // 只打印4个字符
    printf("%.4s\n", str);

    puts(str);
}

/************************************************
 * scanf函数和gets函数进行字符串的读取
 *
 ************************************************/
void scanf_and_gets()
{
    // 经常搞混java与C的数组定义:Java是方括号在类型后，而C语言在变量名后
    // char[10] str;
    // 增加1是为了保留空字符的位置，如此可以输入10个字符
    char str[10 + 1];
    scanf("%s", str);
    printf("scanf str=%s\n", str);

    // warning: this program uses gets(), which is unsafe. 
    // char *str1;
    char str1[10 + 1];
    // gets函数天生就是不安全的，fgets函数则是一种好得多的选择。
    // gets(str1);
    // printf("gets str1=%s\n", str1);
}


/*************************************************
 * 使用C语言的字符串库
 * 1.strcpy 字符串复制string copy 原型:char * strcpy(char *s1, const char *s2); 赋值到s1是完全替换而不是拼接到s1后面
 * 2.strlen 求字符串的长度 原型: size_t strlen(const char *s)
 * 3.strcat 字符串拼接函数 原型: char *strcat(char *s1, const char *s2)
 * 4.strcmp 字符串比较函数 原型: int strcmp(const char *s1, constr char *s2);
 * ***********************************************/
void strcpy_strcat_strcmp()
{
    char str1[100] = "Hi,Lee";
    char *str = str1;

    const char str2[] = "Hi,Jacky";
    const char str3[] = "Hi,Lee";
    printf("str=%s\n", strcat(str, str2));
    printf("str2 compare str3:%d\n", strcmp(str2, str3));
    printf("str1 compare str3:%d\n", strcmp(str1, str3));

    // strlen返回值是unsigned long
    // 返回结果是6，而不是7，也就是不包含空字符的长度; 返回的不是字符数组的长度，而是返回存储在数组中的字符串的长度。
    printf("str1 length=%ld\n", strlen(str1));

    // 此函数在mac平台包含在string.h头文件中定义
    // 用str1与str执行结果有区别
    strcpy(str, "adcdefghijklmnopqrstuvwxyz");
    printf("str=%s\n", str);

    // Illegal instruction: 4 当str1长度不够装时报错
    strcpy(str1, "adcdefghijklmnopqrstuvwxyz");
    printf("str1=%s\n", str1);
}








