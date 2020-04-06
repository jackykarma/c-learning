/* 基本类型 */

#include <stdio.h>

int main(void)
{
   // 1.整数类型：整数short/unsigned short int、int/unsigned int 、long/unsigned long int
   // 整数类型又分为：有符号类型和无符号类型; 带符号位就是第一位被占用作为符号位，它不表示数值而表示正负，0表示正。
   // 16位机器
   // short int: 2Byte -32768——32767 无符号short：0——65535（2^16 -1)
   // int: 2Byte -32768——32767 无符号short：0——65535（2^16 -1)
   // long: 4Byte

   // 32位机器
   // short int: 2个字节
   // int : 4个字节
   // long: 4个字节
   //
   // 64位机器
   // short int: 2个字节
   // int: 4个字节
   // long: 8个字节
   //
   // 2.整数常量
   // 十进制, 不能以0开头
   int a = 10;
   // 八进制, 必须以0开头，表示这是一个八进制树
   int b = 0377;
   // 十六进制, 必须以0x开头
   int c = 0xfe; // 可以大写也可以小写 0xFE

   // 告诉编译器将常量作为长整数来处理
   long d = 900L;
   // 无符号常量
   long e = 800U; 

   // 3.整数溢出
   short f = 32767;
   // 结果：-32768
   short g = f + 1;
   printf("g=%d\n", g);
   short h = 32767U;
   // 结果：32768 不会溢出
   unsigned short i = h + 1;
   printf("i=%d\n", i);

   // --------------------------------
   // 浮点类型：整数部分+小数部分float
   // float: 单精度浮点类型
   // double: 双精度浮点类型
   // long double: 扩展精度浮点数
   // 一般float精度是6个小数、double是15个小数

   // 1.浮点常量
   long j = 57.0F;
   long k = 57.0e0; // 指数形式
   // 默认情况下，浮点常量都以double形式存储；如果指定F或L就会使用float、long double
   double l = 89.9000;
   // 加L强制以long double处理
   long double m = 3.5513343141341341L;
   printf("double l=%lf\n", l);
   printf("long double m=%Lf\n", m);


   // ---------------------------------
   // 字符类型; char类型的值可以根据计算机的不同而不同，因为不同的机器可能会有不同的字符集
   // 请别搞错: 计算机处理的数而不是符号。我们用对行为的算术化程度来衡量我们的理解力（和控制力）
   // char类型是1个字节
   // 无符号类型：unsigned char
   char n = 'A';
   printf("n=%d\n", n);
   printf("n=%c\n", n);
   char o = 'a';
   // 计算机的本质：处理的数而不是符号，因为计算机只能处理二进制; 符号不过是人们提高理解力的一种抽象方式
   // 字符操作
   char no = n + o;
   printf("no=%d\n", no);
   printf("no=%c\n", no);

   // 0-255
   // 明确写出char的类型，避免移植出现问题
   unsigned char p = 'C';
   signed char q = 'A';


   // ---------------------------------
   // 类型转换
   // 小范围到大范围的转换才是合理的，否则存在溢出的可能性
   float x = 87.56f;
   // 强制类型转换
   int y = (int)x;
   // 隐式转换类型
   int z = x;
   printf("y=%d, z=%d\n", y, z);
}


























