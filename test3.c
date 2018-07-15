//杨氏矩阵查找某个数是否存在
    //->从矩阵的右上角开始，若大于key, 说明在当前列的左边,列--；
    //->若当前位置小于key, 说明在当前行的下面行++；
    //-》当前位置一定要保证是在当前行的最右边
#include <stdio.h>
#define ROW 5
#define COL 5

int Find(int a[ROW][COL], int key)
{
    if(a==NULL || ROW<=0 ||COL<=0)
        return -1;
    int row = 0;
    int col = COL-1;
    while(row<ROW && col >= 0)
    {
        if(a[row][col]== key)
            return 1;
        else if(a[row][col] > key)
            col--;
        else
            row++;
    }
    return -1;
}

int Find1(int* a, int rows, int cols, int key)
{
    if(a==NULL || rows<=0 || cols<=0)
        return -1;
    int row = 0;
    int col = cols - 1;
    while(row < rows && col >= 0)
    {
        if(a[row*cols+col] == key)
            return 1;
        else if(a[row*cols+col] > key)
            --col;
        else
            ++row;
    }
    return -1;
}

int main()
{
    int a[5][5] = {-3, -1, 0, 2, 5,
                    1, 3, 4, 5, 6,
                    2, 7, 9, 10, 12,
                    4, 9, 12, 13, 14,
                    6, 10, 15, 20, 25};
    int ret1 = Find(a, 5);
    int ret2 = Find(a, -3);
    int ret3 = Find(a, 25);
    int ret4 = Find(a, 4);
    int ret5 = Find(a, 6);
    int ret6 = Find(a, 8);
    printf("expected is 1, actual is %d\n", ret1);
    printf("expected is 1, actual is %d\n", ret2);
    printf("expected is 1, actual is %d\n", ret3);
    printf("expected is 1, actual is %d\n", ret4);
    printf("expected is 1, actual is %d\n", ret5);
    printf("expected is -1, actual is %d\n", ret6);

    int a1[25] = {-3, -1, 0, 2, 5, 1, 3, 4, 5, 6, 2, 7, 9, 10, 12, 4, 9, 12, 13, 14, 6, 10, 15, 20, 25};
    ret1 = Find1(a1, 5, 5, 5);
    ret2 = Find1(a1, 5, 5, -3);
    ret3 = Find1(a1, 5, 5, 25);
    ret4 = Find1(a1, 5, 5, 4);
    ret5 = Find1(a1, 5, 5, 6);
    ret6 = Find1(a1, 5, 5, 8);
    printf("\nexpected is 1, actual is %d\n", ret1);
    printf("expected is 1, actual is %d\n", ret2);
    printf("expected is 1, actual is %d\n", ret3);
    printf("expected is 1, actual is %d\n", ret4);
    printf("expected is 1, actual is %d\n", ret5);
    printf("expected is -1, actual is %d\n", ret6);
    return 0;
}
