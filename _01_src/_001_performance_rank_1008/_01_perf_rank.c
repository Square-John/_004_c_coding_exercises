/*
1、题目描述
给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以及90分以上为A，80-89分为B，70-79分为C，60-69分为D，60分以下为E。
2、输入格式
一个整数0－100以内
3、输出格式
一个字符，表示成绩等级
4、样例输入
90
5、样例输出
A

*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int score; // 用于保存输入分数
    char rank; // 用于保存分数对应等级

    // printf("请输入一个0~100之间的整数 \n");

    if (scanf("%d", &score) != 1 || score < 0 || score > 100) // 如果获取键盘输入有误，则结束程序
    {
        return 1;
    }

    if (score >= 90)
    {
        rank = 'A';
    }
    else if (score >= 80)
    {
        rank = 'B';
    }
    else if (score >= 70)
    {
        rank = 'C';
    }
    else if (score >= 60)
    {
        rank = 'D';
    }
    else
    {
        rank = 'E';
    }

    printf("%c \n", rank);

    return 0;
}
