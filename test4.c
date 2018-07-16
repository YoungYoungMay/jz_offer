//将字符串中的空格都替换为"%20"
#include <stdio.h>
#include <string.h>

//这里的len是字符数组的总长度
void ReplaceBlank(char str[], int len)
{
    if(str==NULL || len<=0)
        return;
    //1.先计算出替换后字符串的长度
        //（1）先计算源字符串长度、空格个数
    int i = 0;
    int blank = 0;
    int ori_size = 0;
    while(str[i] != '\0')
    {
        ++ori_size;
        if(str[i] == ' ')
            ++blank;
        ++i;
    }
        //(2)新字符串长度是源字符串长度+2*空格个数
    int new_size = ori_size + 2*blank;

    //2.进行替换
    int ori_index = ori_size;
    int new_index = new_size;
    while(ori_index>=0 && new_index>ori_index)
    {
        if(str[ori_index] == ' ')
        {
            str[new_index--] = '0';
            str[new_index--] = '2';
            str[new_index--] = '%';
            ori_index--;
        }
        else
            str[new_index--] = str[ori_index--];
    }
}

int main()
{
    char str[30] = "This is YoungMay!";
    printf("替换前：%s\n", str);
    ReplaceBlank(str, 30);
    printf("替换后：%s\n", str);
    
    char str1[30] = "";
    printf("\n替换前：%s\n", str1);
    ReplaceBlank(str1, 30);
    printf("替换后：%s\n", str1);
    
    char str2[30] = " ThisisYoungMay!";
    printf("\n替换前：%s\n", str2);
    ReplaceBlank(str2, 30);
    printf("替换后：%s\n", str2);
    
    char str3[30] = "This is   YoungMay!";
    printf("\n替换前：%s\n", str3);
    ReplaceBlank(str3, 30);
    printf("替换后：%s\n", str3);
    
    char str4[30] = "ThisisYoungMay!";
    printf("\n替换前：%s\n", str4);
    ReplaceBlank(str4, 30);
    printf("替换后：%s\n", str4);

    char str5[30] = "ThisisYoungMay! ";
    printf("\n替换前：%s\n", str5);
    ReplaceBlank(str5, 30);
    printf("替换后：%s\n", str5);
    
    char str6[30] = "Thisis YoungMay!";
    printf("\n替换前：%s\n", str6);
    ReplaceBlank(str6, 30);
    printf("替换后：%s\n", str6);

    return 0;
}
