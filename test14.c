//调整数组顺序，使得奇数位于偶数的前面

#include <stdio.h>

//解法1-》较简单
void ReorderOddEven(int* data, unsigned int length)
{
    if(data==NULL || length==0)
        return;
    int* left = data;
    int* right = data + length-1;
    while(left < right)
    {
        while(left<right && (*left&0x1)!=0)
            left++;//指向奇数
        while(left<right && (*right&0x1)==0)
            right--;//指向偶数
        if(left < right)
        {
            int tmp = *left;
            *left = *right;
            *right = tmp;
        }
    }
}

//解法2-》推荐
    //可复用，传入函数指针，控制调整条件
int isEven(int n)//控制调整条件，可改变
{
    return (n&1)==0;
}

void ReorderOddEven1(int* data, unsigned int length, int (*func)(int))
{
    if(data==NULL || length==0)
        return;
    int* left = data;
    int* right = data+length-1;
    while(left < right)
    {
        while(left<right && !func(*left))
            left++;
        while(left<right && func(*right))
            right--;
        if(left < right)
        {
            int tmp = *left;
            *left = *right;
            *right = tmp;
        }
    }
}

void Print(int* data, int len)
{
    int i = 0;
    for(; i<len; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void Test()
{
    int data[] = {3, 2, 1, 4, 6, 9, 11, 14, 15};
    int size = sizeof(data)/sizeof(data[0]);
    Print(data, size);
    ReorderOddEven(data, size);
    Print(data, size);
}

void Test1()
{
    int data[] = {3, 2, 1, 4, 6, 9, 11, 14, 15};
    int size = sizeof(data)/sizeof(data[0]);
    Print(data, size);
    ReorderOddEven1(data, size, isEven);
    Print(data, size);
}

int main()
{
    Test();
    Test1();
    return 0;
}
