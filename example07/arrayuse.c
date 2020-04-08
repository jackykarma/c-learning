/* C语言数组类型 */

#include <stdio.h>

int main()
{
    // 1. 一位数组
    // 初始化
    int arr1[3] = { 1, 3, 5 };
    // 如果给出了初始化列表，那么数组size可以省略不写，建议还是写吧
    int arr12[] = { 1, 3, 5, 7, 9 };
    // 常量数组
    const int arr2[2] = { 2, 4 };

    // 错误写法: 必须显示指明数组的大小
    // int arr3[];
    int arr5[2];
    // 错误写法：不能先声明数组，然后给数组名赋值，因为数组名其实是数组的首元素地址; 对于多维数组也是如此
    // arr5 = {2,3};
    arr5[0] = 2;
    arr5[1] = 3;
    int arr4[4];
    for(int i = 0; i < 4; i++)
    {
	// 将用户输入的值赋给arr4数组中的元素
	printf("Please input arr4[%d]: ", i);
	scanf("%d", &arr4[i]);
    }
    // 修改数组元素值
    arr4[3] = 298;
    for(int j = 0; j < 4; j++)
    {
	printf("arr4[%d] = %d\n", j, arr4[j]);
    }

    // 字符数组
    char atoc[3] = { 'a', 'b', 'c' };
    int atocsize = sizeof(atoc);
    int atocelementsize = sizeof(atoc[0]);
    int atoclength = atocsize / atocelementsize;
    printf("atocsize:%d, atocelementsize=%d, atoclength=%d\n", atocsize, atocelementsize, atoclength);

    // 2. 多维数组
    // 声明一个两行三列的二维数组
    int a1[2][3] = {{2,4,6}, 
	  	    {3,5,7}};
    // 声明并初始化
    int b1[2][3] = {{ 1, 2, 3}, 
	    	    { 4, 5, 6}};
    for(int i = 0; i < 2; i++)
    {
	// 打印第i行的所有数据
	printf("第%d行数据是: %d, %d, %d\n", i + 1, a1[i][0], a1[i][1], a1[i][2]);
    }

    // C99标准中可变长度数组
    int n;
    printf("Please input array length:");
    // 程序运行时决定的长度，而不是静态编译时就定下数组长度
    scanf("%d", &n);
    int vara[n];

    for(int i = 0; i < n; i++)
    {
	scanf("%d", &vara[i]);
    }
    for(int i = 0; i < n; i++)
    {
	printf("vara[%d] = %d\n", i, vara[i]);
    }
}
