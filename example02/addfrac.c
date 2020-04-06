/* Adds two fractions 分数相加 */

#include <stdio.h>

// 为了显示scanf函数的模式匹配能力，考虑读入由用户键入的分数。
// 分数通常的形式为分子/分母。scanf函数允许读入整个分数，而不用
// 将分子和分母视为两个整数分别读入。
int main()
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter first fraction:");
    // 注意：/ 作为字符存在 形式变为num1/denom1, 分子/分母作为了一个整体
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction:");
    scanf("%d/%d", &num2, &denom2);
   
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}
