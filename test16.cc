//反转链表

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

//解法1
    //将下一个节点一直头插
void ReverseList(ListNode** head)
{
    if(head==NULL || *head==NULL ||(*head)->next==NULL)
        return;
    ListNode* cur = *head;
    while(cur->next != NULL)
    {
        ListNode* to_insert = cur->next;
        cur->next = to_insert->next;
        to_insert->next = *head;
        *head = to_insert;
    }
}

//解法2
    //依次将next指针改变
void ReverseList1(ListNode** head)
{
    if(head==NULL || *head==NULL || (*head)->next==NULL)
        return;
    ListNode* pre = NULL;//保证逆置后的链表最后一个节点指向NULL
    ListNode* cur = *head;
    while(cur != NULL)
    {
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    *head = pre;//调整头结点
}

void Test()
{
    ListNode* head;
    ListInit(&head);
    ListPushFront(&head, 1);
    ListPushFront(&head, 2);
    ListPushFront(&head, 3);
    ListPushFront(&head, 4);
    Print(head);
    ReverseList(&head);
    Print(head);
}

void Test1()
{
    cout<<endl;
    ListNode* head;
    ListInit(&head);
    ListPushFront(&head, 1);
    ListPushFront(&head, 2);
    ListPushFront(&head, 3);
    ListPushFront(&head, 4);
    Print(head);
    ReverseList1(&head);
    Print(head);
}

int main()
{
    Test();
    Test1();
    return 0;
}
