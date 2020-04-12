// 头文件中的#error指令，用于检查不应该包含头文件的条件
#ifndef __STDC__
#error This header requires a Standard C compiler
#endif

// 头文件保护, 避免在其他文件被重复导入
#ifndef FILE1_H
#define FILE1_H


// 宏定义、类型定义
#define PIE 3.14
typedef int BOOL;

// 共享外部变量
// 共享shared int
// int shared = 100;

// 共享函数原型
// 函数原型：求和计算
int sum(int a, int b);
// 函数原型：面积计算
float area(float r);

#endif
