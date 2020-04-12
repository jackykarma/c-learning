// 头文件中的#error指令，用于检查不应该包含头文件的条件
#ifndef __STDC__
#error This header requires a Standard C compiler
#endif

// 头文件保护, 避免在其他文件被重复导入
#ifndef FILE2_H
#define FILE2_H

// 嵌套file.h，起始file2.h就完全包含了file1.h; 对外使用的时候file2.h如果包含，就不应该再包含file1.h
#include "file1.h"


// 宏定义、类型定义
#define HELLO_WROLD "Hello, World\n"
#define PRINT_INT(n) printf(#n " = %d\n", n)
#define PRINT_FLOAT(n) printf(#n " = %f\n", n)
typedef unsigned int UINT_32;

// 共享外部变量
float exfloat;

// 共享函数原型
float max_float(float x, float y);

#endif
