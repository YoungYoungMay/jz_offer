//求旋转数组中最小的数
    //如{3,4,5,1,2}是{1,2,3,4,5}的一个旋转，输出的最小值为1

//1.直接给数组排序，输出第一个元素
int minNumberInRotateArray(vector<int> rotateArray) 
{
    sort(rotateArray.begin(),rotateArray.end());
        return rotateArray[0];                
}

//2.定义一个最小值为第一个元素，遍历依次比较
int minNumberInRotateArray(vector<int> rotateArray) 
{
    if(rotateArray.empty())
        return 0;
    int min = rotateArray[0];
    for(int i=1; i<rotateArray.size(); ++i)
    {
        if(rotateArray[i] < min)        
            min = rotateArray[i];                       
    }
    return min;                                    
}

//3.利用二分法，经过旋转的数组，两段相邻的分别是最大值和最小值
int minNumberInRotateArray(vector<int> rotateArray)
{
    if(rotateArray.empty())
        return 0;
    int left = 0;
    int right = rotateArray.size()-1;
    int res = left;
    while(rotateArray[left] >= rotateArray[right])//当前数组是经过旋转的
    {
        //前半段一定是递增的，后半段一定是递减的
        if(right-left == 1)
        {
            res = right;
            break;
        }
        //若直接将left与right相加除2，若相加结果过大，再给int型，会变成负数
        res = left + (right-left)/2;
        if(rotateArray[left] <= rotateArray[res])
            left = res;
        else if(rotateArray[right] >= rotateArray[res])
            right = res;
    }
    return rotateArray[res];
}
