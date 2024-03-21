/*
题目描述
求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。

输入格式
n

输出格式
Sn的值

样例输入
5
样例输出
24690
*/

#include <stdio.h>

#define A 2
#define DEC 10

// 用于获取第n项an的值
// int a,表示数字a，等于2
// int n 表示第n项
int get_an(int a, int n);

int main(int argc, char const *argv[])
{
    int n;
    int sn = 0;

    // 输入并验证输入合法性，如果输入不合法则退出程序
    if (scanf("%d", &n) != 1 || n < 0)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {

        sn += get_an(A, i + 1);
    }
    printf("%d\n", sn);

    return 0;
}

// 用于获取第n项的值
// int a,表示数字a，等于2
// int n 表示第n项
int get_an(int a, int n)
{

    int sum = 0;      // 第n项和
    int dec_multiple; // 十的倍数

    //计算sn的值
    for (int i = 0; i < n; i++)
    {
        dec_multiple = 1;
        for (int j = 0; j < i; j++)
        {
            dec_multiple *= DEC;
        }

        sum += a * dec_multiple;
    }

    return sum;
}
