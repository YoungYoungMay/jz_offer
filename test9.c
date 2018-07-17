//斐波那契数列
//0,1...后面的数是前面两个数的和(从第0个开始数)
    //-》(1)递归实现---面试可能不够，递归效率太低
    //-》(2)把之前得到的值保存起来，减少做重复事情的概率-----推荐
    //-》(3)还有一种更快的算法，用一个比较生辟的数学公式实现，但是不常用

#include <stdio.h>

//(1)递归实现
long long Fibonacci1(int n)
{//这里long long类型可以用%lld、%llu分别表示有符号类型、无符号类型
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci1(n-1)+Fibonacci1(n-2);
}

//(2)改进算法
long long Fibonacci2(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    size_t numpreone = 1;
    size_t numpretwo = 0;
    size_t sum = 0;
    int i = 0;
    for(i=2; i<=n; i++)
    {
        sum = numpreone + numpretwo;
        numpretwo = numpreone;
        numpreone = sum;
    }
    return sum;
}

void Test1()
{
    long long res = Fibonacci1(5);
    printf("%lld\n", res);
    long long res1 = Fibonacci1(0);
    printf("%lld\n", res1);
    long long res2 = Fibonacci1(1);
    printf("%lld\n", res2);
    long long res3 = Fibonacci1(2);
    printf("%lld\n", res3);
    long long res4 = Fibonacci1(10);
    printf("%lld\n", res4);
    long long res5 = Fibonacci1(-3);
    printf("%lld\n", res5);
}

void Test2()
{
    long long res = Fibonacci1(5);
    printf("\n%lld\n", res);
    long long res1 = Fibonacci1(0);
    printf("%lld\n", res1);
    long long res2 = Fibonacci1(1);
    printf("%lld\n", res2);
    long long res3 = Fibonacci1(2);
    printf("%lld\n", res3);
    long long res4 = Fibonacci1(10);
    printf("%lld\n", res4);
    long long res5 = Fibonacci1(-3);
    printf("%lld\n", res5);
}

int main()
{
    Test1();
    Test2();
    return 0;
}
