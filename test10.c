//左移<<补0，右移>>补符号位

//求二进制中1的个数
    //-》这里如果传入参数为负数，用补码计算1的个数
#include <stdio.h>

//(1)
    //-》如果n确定类型，也可以用i控制循环次数为n的位数
    //-》这里移位操作不能换为除2操作，因为除法操作比移位操作的效率低的多
int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(flag & n)
            count++;
        flag <<= 1;
    }
    return count;
}

//(2)推荐解法
    //-》把一个整数-1与原整数做与运算，使得整数的二进制序列最后一个1变成0
int NumberOf1_(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = (n-1)&n;
    }
    return count;
}

void Test()
{
    int ret = NumberOf1(-1);
    int ret1 = NumberOf1(0);
    int ret2  = NumberOf1(1);
    int ret3 = NumberOf1(20);
    int ret4 = NumberOf1(-5);
    printf("32 = %d\n", ret);
    printf("0 = %d\n", ret1);
    printf("1 = %d\n", ret2);
    printf("2 = %d\n", ret3);
    printf("31 = %d\n", ret4);
}

void Test1()
{
    int ret = NumberOf1_(-1);
    int ret1 = NumberOf1_(0);
    int ret2  = NumberOf1_(1);
    int ret3 = NumberOf1_(20);
    int ret4 = NumberOf1_(-5);
    printf("\n32 = %d\n", ret);
    printf("0 = %d\n", ret1);
    printf("1 = %d\n", ret2);
    printf("2 = %d\n", ret3);
    printf("31 = %d\n", ret4);
}

int main()
{
    Test();
    Test1();
    return 0;
}
