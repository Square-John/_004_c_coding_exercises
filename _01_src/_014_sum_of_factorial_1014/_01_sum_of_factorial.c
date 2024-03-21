/*
题目描述
求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字(n不超过20)。

输入格式
n
输出格式
Sn的值

样例输入
5
样例输出
153
*/

#include <stdio.h>

// 计算一个数字的阶乘

long factorial(int n);

int main(int argc, char const *argv[])
{
    // 变量声明和定义
    long Sn; // Sn的和
    int n;   // 一个非负数且不大于20

    // 获取数字n的输入，并做合法性判断

    if (scanf("%d", &n) != 1 || n < 0 || n > 20)
    {
        return 1; // 获取输入有误则退出程序并返回1
    }
    // n = 5;

    // 初始化Sn = 0
    Sn = 0;

    // 计算Sn的值
    // 0的阶乘等于1
    if (n == 0)
    {
        Sn = 1;
    }
    // 大于零的n的阶乘之和
    else
    {
        for (int i = 1; i <= n; i++)
        {
            Sn += factorial(i);
        }
    }

    // 打印Sn的值
    printf("%ld\n", Sn);

    return 0;
}

// 计算n的阶乘,n > 0
long factorial(int n)
{
    long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}