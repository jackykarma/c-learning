// 头文件中的#error指令，用于检查不应该包含头文件的条件
#ifndef __STDC__
#error This header requires a Standard C compiler
#endif

// 头文件保护, 避免在其他文件被重复导入
#ifndef FILE3_H
#define FILE3_H

// 共享函数原型
int max_int(int x, int y);

#endif
