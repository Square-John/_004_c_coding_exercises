/*
1、题目描述
企业发放的奖金根据利润I提成。
利润I低于或等于100000元的，奖金可提10%;
利润高于100000元，低于或等于200000元（100000<I≤200000）时，低于等于100000元部分按10％提成，高于100000元的部分，可提成 7.5%;
200000<I≤400000时，低于200000元部分仍按上述办法提成（下同），高于200000元的部分按5％提成；
400000<I≤600000元时，高于400000元的部分按3％提成；
600000<I≤1000000时，高于600000元的部分按1.5%提成；
I>1000000时，超过1000000元的部分按1%提成。
从键盘输入当月利润I,求应发奖金总数。
2、输入格式
一个整数，当月利润。
3、输出格式
一个整数，奖金。
4、样例输入
900
5、样例输出
90
*/

#include <stdio.h>

// 利润I低于或等于100000元的，奖金可提10%;
#define PROFIT_RANK_1 100000
#define RATE_1 0.1
#define CREDIT_1 (PROFIT_RANK_1 * RATE_1)

// 利润高于100000元，低于或等于200000元（100000<I≤200000）时，高于100000元的部分，可提成 7.5%
//本级利润上限
#define PROFIT_RANK_2 200000
//本级奖金率
#define RATE_2 0.075
//本级奖金上限值
#define CREDIT_2 (((PROFIT_RANK_2 - PROFIT_RANK_1) * RATE_2) + CREDIT_1)

// 200000<I≤400000时，高于200000元的部分按5％提成；
#define PROFIT_RANK_3 400000
#define RATE_3 0.05
#define CREDIT_3 (((PROFIT_RANK_3 - PROFIT_RANK_2) * RATE_3) + CREDIT_2)

// 400000<I≤600000元时，高于400000元的部分按3％提成；
#define PROFIT_RANK_4 600000
#define RATE_4 0.03
#define CREDIT_4 (((PROFIT_RANK_4 - PROFIT_RANK_3) * RATE_4) + CREDIT_3)

// 600000<I≤1000000时，高于600000元的部分按1.5%提成；
#define PROFIT_RANK_5 1000000
#define RATE_5 0.015
#define CREDIT_5 (((PROFIT_RANK_5 - PROFIT_RANK_4) * RATE_5) + CREDIT_4)

// I>1000000时，超过1000000元的部分按1%提成。
#define RATE_6 0.01

int main(int argc, char const *argv[])
{
    int profit;     // 企业利润
    int credit; // 奖金

    // 输入利润，如果输入有误则直接退出程序
    if (scanf("%d", &profit) != 1 || profit < 0)
    {
        return 1;
    }

    if (profit <= PROFIT_RANK_1)
    {
        credit = (int)(profit * RATE_1);
    }
    else if (profit <= PROFIT_RANK_2)
    {
        credit = (int)((profit - PROFIT_RANK_1) * RATE_2 + CREDIT_1);
    }
    else if (profit <= PROFIT_RANK_3)
    {
        credit = (int)((profit - PROFIT_RANK_2) * RATE_3 + CREDIT_2);
    }
    else if (profit <= PROFIT_RANK_4)
    {
        credit = (int)((profit - PROFIT_RANK_3) * RATE_4 + CREDIT_3);
    }
    else if (profit <= PROFIT_RANK_5)
    {
        credit = (int)((profit - PROFIT_RANK_4) * RATE_5 + CREDIT_4);
    }
    else
    {
        credit = (int)((profit - PROFIT_RANK_5) * RATE_6 + CREDIT_5);
    }
    
    printf("%d\n", credit);

    return 0;
}
