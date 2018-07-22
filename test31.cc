//求数组连续子数组和的最大值(数组有正有负)
    //-》1.从第一个数字向后求和
    //-》2.加至结果和

//#include <iostream>
//using namespace std;
#include <stdio.h>

int error = 0;

//(1)解法1-》该方法对于全是负数的数组不能正确的计算出结果
int FindGreatestSumOfArray(int* arr, int length)
{
    if(arr==NULL || length<=0)//非法输入
    {
        error = 1;
        return 0;
    }
    int sum = arr[0];
    int greatest_sum = arr[0];//0x80000000;//16进制数，转化为int表示0
    printf("greatest_sum=%d\n", greatest_sum);
    int i = 1;
    for(; i<length; ++i)
    {
        if(sum <= 0)
            sum = arr[i];
        else
            sum += arr[i];
        if(sum > greatest_sum)
            greatest_sum = sum;
    }
    return greatest_sum;
}

//(2)解法2-》动态规划解法-》同样不支持全为负数的数组

int main()
{
    int arr[10] = {1, -2, 3, 10, -4, 7, 2, -5};
    int res = FindGreatestSumOfArray(arr, sizeof(arr)/sizeof(arr[0]));
    printf("18 = %d\n", res);
    
    int arr1[10] = {-3, -2, -1, -5, -4, -7, -10, -5};
    int res1 = FindGreatestSumOfArray(arr1, sizeof(arr1)/sizeof(arr1[0]));
    if(error == 0)
        printf("-1 = %d\n", res1);
    
    int arr2[10] = {1, 2, 3, 10, 4, 7, 2, 5};
    int res2 = FindGreatestSumOfArray(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printf("34 = %d\n", res2);


    return 0;
}
