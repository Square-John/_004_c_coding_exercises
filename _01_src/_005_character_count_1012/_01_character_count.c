/*
题目描述
输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。

输入格式
一行字符,长度不超过200

输出格式
统计值

样例输入
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123
样例输出
23 16 2 4
*/

#include <stdio.h>
// #include <string.h>

#define STR_MAX_LEN 101

int main(int argc, char const *argv[])
{

    char str[STR_MAX_LEN]; // 保存输入字符
    int eng_count = 0;      // 英文字母个数
    int digit_count = 0;    // 数字个数
    int space_count = 0;    // 空格个数
    int other_count = 0;    // 其他字符个数

    if (!fgets(str, STR_MAX_LEN, stdin))
    {
        return 1; // 如果输入错误则返回1，并退出程序
    }

    for (int i = 0; str[i] && str[i] != '\n'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            eng_count++;
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            eng_count++;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            digit_count++;
            continue;
        }
        if (str[i] == ' ')
        {
            space_count ++;
            continue;
        }
 
        other_count ++;
    }

    printf("%d %d %d %d\n", eng_count, digit_count, space_count, other_count);

    return 0;
}
