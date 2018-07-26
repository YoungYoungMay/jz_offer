//合并两个有序的链表
    //-》以升序链表为例

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

ListNode* CreateNewNode(int val)
{
    ListNode* new_node = new ListNode();
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void ListPushFront(ListNode** head, int val)
{
    if(head == NULL)
        return;
    if(*head == NULL)
    {
        *head = CreateNewNode(val);
        return;
    }
    ListNode* new_node = CreateNewNode(val);
    new_node->next = *head;
    *head = new_node;
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

//解法1-》利用指针
    //建立一个新链表，依次将两个链表的节点插入
ListNode* ListMerge(ListNode* head1, ListNode* head2)
{
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    ListNode* ret = NULL;
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1->val < cur2->val)
        {
            ret = cur1;
            cur1 = cur1->next;
            if(tail == NULL)
            {
                head = tail = ret;
            }
            else
            {
                tail->next = ret;
                tail = ret;
            }
        }
        else
        {
            ret = cur2;
            cur2 = cur2->next;
            if(tail == NULL)
            {
                head = tail = ret;
            }
            else
            {
                tail->next = ret;
                tail = ret;
            }
        }
    }
    if(cur1 == NULL)
        tail->next = cur2;
    if(cur2 == NULL)
        tail->next = cur1;
    return head;
}

void Test()
{
    ListNode* head1;
    ListInit(&head1);
    ListPushFront(&head1, 4);
    ListPushFront(&head1, 3);
    ListPushFront(&head1, 2);
    ListPushFront(&head1, 1);
    Print(head1);

    ListNode* head2;
    ListInit(&head2);
    ListPushFront(&head2, 7);
    ListPushFront(&head2, 6);
    ListPushFront(&head2, 4);
    ListPushFront(&head2, 2);
    Print(head2);

    ListNode* head = ListMerge(head1, head2);
    Print(head);
}

int main()
{
    Test();
    return 0;
}
