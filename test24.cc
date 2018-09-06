//栈的压入、弹出序列
    //给定两个序列，一个为栈的入栈序列，一个为出栈序列
    //看出栈序列是否为给定入栈序列的出栈


bool IsPopOrder(vector<int> pushV,vector<int> popV) 
{
    //辅助栈
    stack<int> s;
    //当入栈序列全部入辅助栈，但栈顶元素与出栈序列当前序列不一致，返回false
    for(int i=0,j=0; j<pushV.size(); )
    {
        //先入栈，并将入栈序列后移
        s.push(pushV[i++]);
        //当前栈顶元素与出栈当前元素一致，出栈并让出栈序列后移
        while(j<popV.size() && s.top()==popV[j])
        {
            s.pop();
            j++;
        }
    }
    if(s.empty())
        return true;
    return false;
}
