//求数组中的逆序对
    //两两比较，前面的数大于后面的数，即构成逆序对


//1.简单粗暴的O(n)实现
int InversePairs(vector<int> data) 
{
    if(data.empty())
        return 0;
    int i = 0;
    int count = 0;
    for(; i<data.size(); ++i)
    {
        int j = i+1;
        for(; j<data.size(); ++j)
        {
            if(data[i] > data[j])
                count++;
        }
    }
    return count;
}

//2.利用归并排序实现O(N(logN))时间复杂度
int InversePairs(vector<int> data) 
{
    int length=data.size();
    if(length <= 0)
        return 0;
    vector<int> copy(length);
    for(int i=0; i<length; i++)
        copy[i] = data[i];
    long long count = InversePairsCore(data,copy,0,length-1);
    return count%1000000007;
}

long long InversePairsCore(vector<int>& data,vector<int>& copy,int start,int end)
{
    if(start == end)
    {
        copy[start]=data[start];
            return 0;        
    }
     //每次将两块区间进行排序
    int length = (end-start)/2;
    long long left = InversePairsCore(copy,data,start,start+length);
    long long right = InversePairsCore(copy,data,start+length+1,end); 
    int i = start+length;
    int j = end;
    int indexcopy = end;
    long long count = 0;
    //有一个区间排列完循环就结束，剩下的区间元素可以直接插入
    while(i>=start && j>=start+length+1)
    {
        //因为传入的两个区间有序，所以它比最后一个数大就一定比整个区间的数大
        if(data[i] > data[j])
        {
            copy[indexcopy--] = data[i--];
            count = count+j-start-length;
        }
         else
         {
             copy[indexcopy--]=data[j--];                            
         }
    }
    for(; i>=start; i--)
        copy[indexcopy--] = data[i];
    for(; j>=start+length+1; j--)
        copy[indexcopy--] = data[j];
    return left+right+count;
}
