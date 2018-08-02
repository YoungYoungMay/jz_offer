//顺时针打印矩阵
#include <iostream>
using namespace std;

//解法1
void PrintMatrixInCircle(int numbers[5][5], int cols, int rows, int start)//打印每个矩阵-》即每一圈
{
    int end_x = cols-1-start;//控制行元素的结束位置
    int end_y = rows-1-start;//控制列元素的结束位置

    //从左到右打印一行
    int i = start;
    for(; i<=end_x; ++i)
    {
        int num = numbers[start][i];
        cout<<num<<" ";
    }

    //从上到下打印一列
    if(start < end_y)
    {
        for(i=start+1; i<=end_y; ++i)
        {
            int num = numbers[i][end_x];
            cout<<num<<" ";
        }
    }
    
    //从右向左打印一行
    if(start<end_x && start<end_y)
    {
        for(i=end_x-1; i>=start; --i)
        {
            int num = numbers[end_y][i];
            cout<<num<<" ";
        }
    }

    //从下到上打印一行
    if(start<end_x && start<end_y-1)
    {
        for(i=end_y-1; i>start; --i)
        {
            int num = numbers[i][start];
            cout<<num<<" ";
        }
    }
}

void PrintMatrixClockwisely(int numbers[5][5], int cols, int rows)//依次打印矩阵-》即共打印的几圈
{
    if(numbers==NULL || cols<=0 || rows==0)
        return;
    int start = 0;//(start,start)为整个矩阵的左上角位置的元素
    while(cols>start*2 && rows>start*2)//控制矩阵的打印结束
    {
        PrintMatrixInCircle(numbers, cols, rows, start);
        ++start;
    }
}

//解法2
void _Print(int a[5][5], size_t r, size_t c, size_t row, size_t col)
{//传入的第二、三个参数表示当前顺时针圈的起始位置
 //传入的第四、五的参数为当前圈的行、列的最大值
	size_t i = r;
	size_t j = c;
	//1.从左向右打
	for (; j < col; ++j)
	{
        cout<<a[i][j]<<" ";
	}
	//2.从上向下打
	j--;//上个循环结束在j = col
	for (i++; i < row; ++i)//i++避免重复打印
	{
        cout<<a[i][j]<<" ";
	}
	//3.从右向左打
	i--;//上个循环结束在i = row
	for (j--; j > c; --j)//j--避免重复打印
	{
        cout<<a[i][j]<<" ";
	}
	//4.从下向上打
	//上个循环在j = c(起始位置的列)
	for (; i > r; --i)//上个循环j=c未打印，所以这里不用i++避免重复打印
	{
        cout<<a[i][j]<<" ";
	}
}
 
void Print(int a[5][5], size_t row, size_t col)
{
	size_t i = 0;
	size_t j = 0;
	while (i < row && j < col)
	{
		_Print(a, i, j,row, col);
		i++;
		j++;//每圈打印完，起始位置i,j都要++
		row--;
		col--;//每圈打完，当前矩阵行、列的最大值也要减1
	}
	cout<<endl;
}
int main()
{
    int a[5][5] = {1, 2, 3, 4, 5,
                  6, 7, 8, 9 , 10,
                 11, 12, 13, 14, 15,
                 16, 17, 18, 19, 20};        
    PrintMatrixClockwisely(a, 5, 5);
    cout<<endl;

    Print(a, 5, 5);
    return 0;
}
