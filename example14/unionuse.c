/* 联合 union */

#include <stdio.h>

// 联合也是由一个或多个成员构成的，而且这些成员可能具有不同的类型。但是，编译器只是
// 为联合中最大的成员分配足够的内存空间。联合的成员在这个空间内彼此覆盖。这样的结果是，
// 给一个成员赋予新值也会改变其他成员的值。
//
//
// 联合的作用：
// 1. 节省空间：在结构中经常使用联合作为节省空间的一种方法。比如对于不同的选择要存储的数据是不同的。因此没有必要将所有数据的存储空间全部包含，这样浪费空间。
// 2. 构造混合的数据结构：创建含有不同类型的混合数据的数据结构。必须现在需要数组的元素是int值和double值的混合。因为数组的元素必须是相同的类型，所以好像
// 不可能产生如此类型的数组。但是，利用联合这件事就相对容易了。首先，定义一种联合类型，它所包含的成员分别表示要存储在数组中的不同数据类型:
// TODO: 用struct是有区别的，struct是包含int和double，而union是要么包含int，要么包含double 
typedef union {
    int i;
    double d;
} Number;

Number number_array[100];

// 为联合添加标记字段
// 联合所面临的主要问题是：不容易确定联合最后改变的成员，因此所包含的值可能是无意义的。对于Number数组，你可能不知道当前的元素到底是int还是double
#define INT_KIND 0
#define DOUBLE_KIND 1

typedef struct {
    int kind; /* tag field 标记字段 */
    union {
	int i;
	double d;
    } u;
} Number_improve;

Number_improve number_arr[10];

void print_number(Number_improve n)
{
    if(n.kind == INT_KIND)
	printf("%d\n", n.u.i);
    else
	printf("%f\n", n.u.d);
}

// 结构变量s与联合变量u只有一处不同：s的成员存储在不同的内存地址中，而u的成员存储在同一内存地址中。
// union的初始化与struct一直
union {
    int i;
    double d;
} u;

struct {
    int i;
    double d;
} s;

int main()
{
    for(int k = 0; k < 10; k++) {
	// 偶数位置的元素填充整型值
        if(k%2 == 0)
	{
	    number_arr[k].u.i = k + 10;    
	    number_arr[k].kind = INT_KIND;
	}
	// 奇数位置的元素填充double值
	else
	{
     	    number_arr[k].u.d = k + 5.53f;
	    number_arr[k].kind = DOUBLE_KIND;
	}
    }

    for(int i = 0; i < 10; i++)
    {
 	print_number(number_arr[i]);
    }

    return 0;
}
