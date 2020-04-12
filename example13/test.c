// file2.h包含了file1.h
// #include "file1.h"
// 注意外部变量对h文件嵌套的影响
// 如果file1.h包含int x; 而file2.h又include file1.h，那么就会出现重复定义的问题;
// 因为头文件嵌套时，一定不能在被嵌套的头文件中导入外部变量定义。

#include "file2.h"
#include "file3.h"

int main(void)
{
    sum(10, 20);
    area(35.5f);
    max_float(25.8, 10.3);

    max_int(50, 20);
}
