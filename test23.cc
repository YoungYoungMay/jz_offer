//包含min函数的栈
    //定义栈的数据结构，实现一个能够得到栈中最小元素的min函数
    //且在该栈中，push、pop、top、min操作均是O(1)复杂度

private:
    stack<int> stack_data;
    stack<int> stack_min;

//定义两个栈，一个依次入栈
//一个放当前数据栈对应的最小值是几
//数据栈和最小值栈一起入栈，一起出栈

void push(int value) 
{
    if(stack_data.empty())
    {
        stack_data.push(value);
        stack_min.push(value);                      
    }
    else
    {
        stack_data.push(value);
        int ret = stack_min.top();
        if(value < ret)
            stack_min.push(value);
        else
            stack_min.push(ret);
    }
}

void pop() 
{
    stack_data.pop();
    stack_min.pop();        
}

int top() 
{
    return stack_data.top();            
}

int min() 
{
    return stack_min.top();            
}
