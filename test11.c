//求数值的整数次方
//-》不得使用库函数、不需要考虑大数问题
    //-》要考虑到次方可能是0甚至是负数
    //-》注意对0求倒数时，特殊处理：返回值、全局代码、异常，三种方法各有优缺点
    //-》0的0次方无意义，需要特别指出

#include <stdio.h>
#define EXP 0.000001

//-1表示正常，0表示无意义，1表示对0求倒数->不可以
int error = -1;

double mycal(double base, int exponent)//计算正数次的乘方
{
    int i = 1;
    double res = 1;
    for(;i <= exponent; i++)
    {
        res *= base;
    }
    return res;
}

//不能用==直接判断两个小数是否相等，因为计算机表示小数有误差
//-》包括float、double类型
int equal(double num1, double num2)//判断两个小数是否相等
{
    if((num1-num2 > -EXP) && (num1-num2 < EXP))
        return 1;
    return 0;
}

//(1)解法1-》常见，但是可以优化
double Power(double base, int exponent)
{
    double res = 0;
    if(equal(base, 0.0))
    {
        //底数为0，且乘方为负数，会引起求0的倒数的错误
        if(exponent < 0)
        { 
            error = 1;
            return 0.0; 
        }
        //0的0次方没有意义
        if(exponent == 0)
        {
            error = 0;
            return 0.0;
        }
    }
    else 
    {
        //求负数次的乘方
        if(exponent < 0)
        { 
            double ret = mycal(base, -exponent);
            res = 1.0/ret; 
        }
        //可以在计算的函数中包含
        ////求0次方-》1
        //else if(exponent == 0)
        //    return 1.0;
        //求正数次的乘方
        else
            res = mycal(base, exponent);
    }
    return res;
}

//(2)解法2-》优化过，推荐
double Power1(double base, int exponent)
{
    if(equal(base, 0.0) && (exponent<0))
    {
        error = 1;
        return 0.0;
    }
    if(equal(base, 0.0) && (exponent==0))
    {
        error = 0;
        return 0.0;
    }
    int flag = 0;
    if(exponent < 0)
    {
        flag = 1;
        exponent = -exponent;
    }
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double res = Power1(base, exponent>>1);
    res *= res;
    if(exponent & 1 == 1)
        res *= base;
    if(flag == 1)
        res = 1.0/res;
    return res;
}

void Test()
{
    double res = Power(5, 3);
    printf("%lf\n", res);
    double res1 = Power(5, 0);
    printf("%lf\n", res1); 
    double res2 = Power(5, -3);
    printf("%lf\n", res2);
    double res3 = Power(0, 0);
    if(error == 0)
        printf("无意义：%lf\n", res3);
    double res4 = Power(0, -3);
    if(error == 1)
        printf("0不能做分母：%lf\n", res4);
    double res5 = Power(0, 3);
    printf("%lf\n", res5);
    double res6 = Power(-5, 3);
    printf("%lf\n", res6);
    double res7 = Power(-5, -3);
    printf("%lf\n", res7);
}

void Test1()
{
    double res = Power1(5, 3);
    printf("\n%lf\n", res);
    double res1 = Power1(5, 0);
    printf("%lf\n", res1); 
    double res2 = Power1(5, -3);
    printf("%lf\n", res2);
    double res3 = Power1(0, 0);
    if(error == 0)
        printf("无意义：%lf\n", res3);
    double res4 = Power1(0, -3);
    if(error == 1)
        printf("0不能做分母：%lf\n", res4);
    double res5 = Power1(0, 3);
    printf("%lf\n", res5);
    double res6 = Power1(-5, 3);
    printf("%lf\n", res6);
    double res7 = Power1(-5, -3);
    printf("%lf\n", res7);
}

int main()
{
    Test();
    Test1();
    return 0;
}
