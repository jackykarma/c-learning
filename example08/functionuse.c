/* C语言函数 */

#include <stdio.h>

// 函数名：average
// 函数形式参数：2个，分别是a和b，它们的数据类型是double
// 函数返回值类型：double
double average(double a, double b)
{
    double c = (a + b) / 2;
    printf("average c=%f\n", c);
    return c;
}

// 函数声明
double average_2(double a, double b);

// 数组型参数的函数声明
// a[] 数组
// length 必须传递数组的长度，因为函数不知道数组有多长
int sum_array(int a[], int length);

int sum_array2(int a[static 5], int length);

int main()
{
    // 函数调用
    // 实际参数：20.8 和 88.90
    average(20.8, 88.90);

    double x = 20.8;
    double y = 88.90;
    // C语言中，实际参数是通过值传递的
    average_2(x, y);
    printf("x = %f\n", x);

    // 长度至少在5，因为sum_array2 参数数组中有声明static 5
    // 若长度不够，编译报错：array argument is too small; contains 4 elements, callee requires at least 5
    int arr[5] = {6, 8, 10, 15, 20};
    int length = 5;
    // 传递数组名; 本质是数组的地址
    // 函数可以改变数组型形参的元素，且改变会在相应的实际参数中体现出来。
    int sum = sum_array(arr, length);
    printf("sum of array is:%d\n", sum);

    int sum2 = sum_array2(arr, length);
    // TODO:复合字面量：通过指定其包含的元素而创建的没有名字的数组（匿名）
    int sum3 = sum_array2((int []){1,2,3,4,5,6,7}, 7);
    printf("sum2 of array2 is:%d\n", sum2);
    printf("sum3 of array2 is:%d\n", sum3);

    for(int i = 0; i < length; i++)
    {
	printf("arr[%d]=%d\n", i, arr[i]);
    }
}

// 放在函数调用之前实现函数体
double average_2(double a, double b)
{
    // a形参增加20，并不会改变实参x的值
    a += 20; 
    double c = (a +  b) / 2;
    printf("average_2 c=%f\n", c);
    return c;
}

int sum_array(int arr[], int n)
{
    int i, sum = 0;

    for(int i = 0; i < n; i++)
    {
	sum += arr[i];
	// 修改了形式参数数组的元素值
	arr[i] = 15;
    }

    return sum;
}

// static 5提示数组的长度至少是5，别的没有任何影响
int sum_array2(int arr[static 5], int n)
{
    int i, sum = 0;

    for(int i = 0; i < n; i++)
    {
	sum += arr[i];
	// 修改了形式参数数组的元素值
	arr[i] = 15;
    }

    return sum;
}
