//数组中重复的数
    //长度为n且所有主子都在0~n-1范围内
    //数组中某些数字重复，输出第一个重复的数字


bool duplicate(int numbers[], int length, int* duplication
{
    if(numbers==NULL || length<=0)
        return false;
    int hashTable[255] = {0};
    int i = 0;
    //将数组元素存入哈希表中
    for(; i<length; ++i)
    {
        hashTable[numbers[i]]++;
    }
    //依次查找数组中第一个重复的数
    for(i=0; i<length; ++i)
    {
        if(hashTable[numbers[i]] > 1)
        {
            *duplication = numbers[i];
                return true;
        }                
    }
    return false;
}
