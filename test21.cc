//变态跳台阶--斐波那切数列的扩展问题



//该问题转化为数学问题就是阶乘问题
int jumpFloorII(int number) 
{
    if(number == 0)
        return 0;
    int total = 1;
    for(int i=1; i<number; i++)     
        total *= 2;
    return total;                        
}
