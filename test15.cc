//求链表的倒数第k个节点
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

void ListInit(ListNode** head)
{
    *head = NULL;
}

ListNode* CreateNewNode(int value)//创建一个新节点
{
    ListNode* new_node = new ListNode();
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

void PushBack(ListNode** head, int value)
{
    if(head == NULL)//非法输入
        return;
    if(*head == NULL)//链表为空
    {
        *head = CreateNewNode(value);
        return;
    }
    ListNode* cur = *head;//链表非空
    while(cur->next != NULL)
    {
        cur  = cur->next;
    }
    ListNode* new_node = CreateNewNode(value);
    cur->next = new_node;

}

void Print(ListNode* head)
{
    ListNode* cur = head;
    while(cur != NULL)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

//解法1
ListNode* FindKthToTail(ListNode* head, unsigned int k)
{
    if(head == NULL || k<=0)
        return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    size_t i = 0;
    //先让fast走k步
    for(; i<k; ++i)
    {
        if(fast == NULL)
            break;
        fast = fast->next;
    }
    if(i < k)//k超出了链表的长度
        return NULL;
    else
    {
        if(fast == NULL)
            return slow;
        else
        {
            while(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    
    }
}

void Test()
{
    ListNode* head;
    ListInit(&head);
    PushBack(&head, 1);
    PushBack(&head, 2);
    PushBack(&head, 3);
    PushBack(&head, 4);
    Print(head);
    ListNode* res = FindKthToTail(head, 0);
    cout<<"k=0# "<<res<<endl;
    ListNode* res1 = FindKthToTail(head, 1);
    cout<<"k=4# "<<res1->val<<endl;
    ListNode* res2 = FindKthToTail(head, 4);
    cout<<"k=1# "<<res2->val<<endl;
    ListNode* res3 = FindKthToTail(head, 5);
    cout<<"k=0# "<<res3<<endl;
    ListNode* res4 = FindKthToTail(head, 0);
    cout<<"k=0# "<<res4<<endl;

}

int main()
{
    Test();
    return 0;
}
