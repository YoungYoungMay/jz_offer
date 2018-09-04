//两种解法均不理解，解法2输出有问题,解法1与剑指offer不一样

//打印从1到最大的n位数
    //-》若是n位数很大，最后打印出不能用int型接收，这是要注意的一个问题
    //常见的解决大数会用到字符串/数组

#include <iostream>
#include <string.h>
using namespace std;


//(1)解法1-》方法直观、但是代码较长
    //假设要打印1~3位数的所有数，则我们设置一个4位数的字符串
    //全部初始化为0，即看为整数的0
    //然后每次加1，打印出来，直到最高位加到不是0就表示打印结束

bool Increment(char* num)//注意理解!!!字符串表示的数模拟加1
{
    bool isOverflow = false;
    int ret = 0;//表示进位
    int len = strlen(num);
    int i = 0;
    //计算+1的结果
    for(i=len-1; i>=0; i--)
    {
        int sum = num[i] - '0' +ret;//先将字符串转化为整数
        if(i == len-1)
            sum++;
        if(sum >= 10)
        {
            //若在最高位进位，表示已经打印完了
            if(i == 0)
                isOverflow = true;
            else
            {
                sum -= 10;
                ret = 1;
                num[i] = '0' + sum;
            }
        }
        else
        {
            num[i] = '0' + sum;
            break;
        }
    }
    //整数转化为字符串
    return isOverflow;
}

void PrintNum(char* num)
{
    int i = 0;
    while(num[i] == '\0')
        i++;
    cout<<num+i<<" ";
}

void PrintToMaxOfNDigits(int n)
{
    if(n <= 0)
        return;
    //要写n位数，至少得n+1位的字符串
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';

    //只要进位不到最后一个就继续打印
    while(!Increment(num))
    {
        PrintNum(num);
    }
    delete[] num;
}

//(2)解法2-》递归实现，代码简洁??????


int main()
{
    //负数、0、正数
    PrintToMaxOfNDigits(2);
    cout<<endl;
    return 0;
}
