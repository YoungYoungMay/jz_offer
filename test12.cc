//两种解法均不理解，解法2输出有问题,解法1与剑指offer不一样

//打印从1到最大的n位数
    //-》若是n位数很大，最后打印出不能用int型接收，这是要注意的一个问题
    //常见的解决大数会用到字符串/数组

#include <iostream>
#include <string.h>
using namespace std;

//字符串表示的数模拟加1
bool Increment(char* num)//注意理解!!!
{
    bool isOverflow = false;
    int len = strlen(num);
    int i = 0;
    //字符串转化为整数
    for(i=len-1; i>=0; i--)
    {
        num[i] = num[i] - '0';
    }
    //计算+1的结果
    num[len-1]++;
    for(i=len-1; i>=0; i--)
    {
        if(num[i] >= 10)
        {
            //若在最高位进位，表示已经打印完了
            if(i == 0)
            {
                isOverflow = true;
                num[i]--;
            }
            else
            {
                num[i] -= 10;
                num[i-1] += 1;
            }
        }
        else
            break;
    }
    //整数转化为字符串
    for(i=0; i<len; i++)
        num[i] = num[i] + '0';
    return isOverflow;
}

void PrintNum(char* num)
{
    int i = 0;
    while(num[i] == '\0')
        i++;
    cout<<num+i<<" ";
}

//(1)解法1-》方法直观、但是代码较长
void PrintToMaxOfNDigits(int n)
{
    if(n <= 0)
        return;
    //要写n位数，至少得n+1位的字符串
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';

    while(!Increment(num))
    {
        PrintNum(num);
    }
    delete[] num;
}

//(2)解法2-》递归实现，代码简洁
void PrintToMaxOfNDigitsRecursively1(char* num, int length, int index)
{
    if(index == length-1)
    {
        PrintNum(num);
        return;
    }
    int i = 0;
    for(; i<10; i++)
    {
        num[index+1] = i + '0';
        PrintToMaxOfNDigitsRecursively1(num, length, index+1);
    }
}

void PrintToMaxOfNDigits1(int n)
{
    if(n <= 0)
        return;
    char* num = new char[n+1];
    num[n] = '\0';
    int i = 0;
    for(; i<10; i++)
    {
        num[0] = i+'0';
        PrintToMaxOfNDigitsRecursively1(num, n, 0);
    }
    delete[] num;
}

int main()
{
    //负数、0、正数
    PrintToMaxOfNDigits1(3);
    cout<<endl;
    return 0;
}
