//输入两个字符串，从第一个字符串中删除再第二个字符串中出现的每一个字符
#include <iostream>
#include <string>
using namespace std;

void DeleteInStr(string& str, const string& dstr)
{
    if(str.empty() || dstr.empty())
        return;
    size_t i = 0;
    for(; i<dstr.size(); ++i)
    {
        size_t j = 0;
        for(; j<str.size(); ++j)
        {
            if(str[j] == dstr[i])
                str.erase(j, 1);
        }
    }
}

int main()
{
    string str = "They are student.";
    cout<<str<<endl;
    string delete_str = "aeiou";
    DeleteInStr(str, delete_str);
    cout<<str<<endl;
    return 0;
}
