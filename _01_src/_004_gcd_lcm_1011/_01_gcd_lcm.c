/*
1、题目描述
输入两个正整数m和n，求其最大公约数和最小公倍数。
2、输入格式
两个整数
3、输出格式
最大公约数，最小公倍数
4、样例输入
5 7
5、样例输出
1 35
*/

/*
详见：https://oi-wiki.org/math/number-theory/gcd/
最大公约数
定义
最大公约数即为 Greatest Common Divisor，常缩写为 gcd。
一组整数的公约数，是指同时是这组数中每一个数的约数的数。\pm 1 是任意一组整数的公约数。
一组整数的最大公约数，是指所有公约数里面最大的一个。
那么如何求最大公约数呢？我们先考虑两个数的情况。

欧几里得算法
不妨设 a > b
我们发现如果 b 是 a 的约数，那么 b 就是二者的最大公约数。 下面讨论不能整除的情况，即 a = b * q + r，其中 r < b。
我们通过证明可以得到 gcd(a,b)=gcd(b,a mod b)
既然得到了 gcd(a, b) = gcd(b, r)，这里两个数的大小是不会增大的，那么我们也就得到了关于两个数的最大公约数的一个递归求法。
递归至 b == 0（即上一步的 a % b == 0）的情况再返回值即可。

更相减损术
已知两数 a 和 b，求 gcd(a,b)。
不妨设 a ≥ b，若 a = b，则 gcd(a,b)=a=b，否则，gcd(a,b) = gcd(a-b, b)。

Stein 算法的优化
如果a远大于b，且2是a的约数，2不是b的约数，则gcd(a,b) = gcd(a / 2, b)。
*/

/*
最小公倍数
接下来我们介绍如何求解最小公倍数（Least Common Multiple, LCM）
定义
一组整数的公倍数，是指同时是这组数中每一个数的倍数的数。0 是任意一组整数的公倍数。
一组整数的最小公倍数，是指所有正的公倍数里面，最小的一个数。

gcd(a, b) * lcm(a, b) = a * b
所以，要求两个数的最小公倍数，先求出最大公约数即可。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
    2、输入格式
    两个整数
    3、输出格式
    最大公约数，最小公倍数
    4、样例输入
    5 7
    5、样例输出
    1 35
    */
    // 数据定义
    int a, b; // 两个正整数
    int gcd;  // 最大公约数
    int lcm;  // 最小公倍数

    // 1、获取两个正整数
    if (scanf("%d %d", &a, &b) != 2 || a < 1 || b < 1)
    {
        return 1;
    }
    //将a\b原始输入记录保存
    int c = a;
    int d = b;

    do
    {
        // 2、欧几里得算法求最大公约数
        // 2.1 交换大小
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        // printf("a = %d b = %d \n", a, b);

        // 取余
        a = a % b;
        gcd = b;

    } while (a); // 余数不为零时继续

    //3、求最小公倍数
    //由gcd(a, b) * lcm(a, b) = a * b
    //得,lcm(a, b) = a * b / gcd(a, b)
    a = c;
    b = d;
    lcm = a * b / gcd;
    // printf("lcm = %d \n", lcm);

    printf("%d %d\n", gcd, lcm);


    return 0;
}
