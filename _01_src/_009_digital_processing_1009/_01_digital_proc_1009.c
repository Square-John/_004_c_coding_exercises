/*
1、题目描述
给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321,应输出123
2、输入格式
一个不大于5位的数字
3、输出格式
三行 第一行 位数 第二行 用空格分开的每个数字，注意最后一个数字后没有空格 第三行 按逆序输出这个数
4、样例输入
12345
5、样例输出
5
1 2 3 4 5
54321
*/

#include <stdio.h>
#include <math.h>

#define DEC 10 // 十进制

int main(int argc, char const *argv[])
{
    int input_num;      // 输入数字
    int digital;        // 数字位数
    int reverse_output; // 倒序输出数字
    int temp;           // 临时变量
    int mod;

    // 如果输入有误，则退出程序
    // printf("请输入一个非负整数 \n");
    if (scanf("%d", &input_num) != 1 || input_num < 0 || input_num > 99999)
    {
        return 1;
    }

    /*###################### 算数字位数 ############################*/
    digital = 1; // 初始化位数至少为1位
    temp = input_num;
    temp = temp / HEX;
    while (temp > 0)
    {
        digital++;
        temp = temp / HEX;
    }

    // printf("digital = %d \n", digital);
    printf("%d\n", digital);

    /*###################### 将每一位数字输出 ############################*/
    mod = input_num;
    reverse_output = 0;
    // printf("mod = %d \n", mod);

    for (int i = 1; i < digital; i++)
    {
        temp = mod / (int)pow(HEX, digital - i);
        mod = mod % (int)pow(HEX, digital - i);
        reverse_output = reverse_output + temp * (int)pow(HEX, i - 1);
        printf("%d ", temp);
    }

    printf("%d\n", mod);
    reverse_output = reverse_output + mod * (int)pow(HEX, digital - 1);

    printf("%d\n", reverse_output);

    return 0;
}
