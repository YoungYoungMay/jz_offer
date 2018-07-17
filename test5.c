//从尾到头打印链表
    //-》1.改变next指针的指向(提供将头节点之后的节点依次头插实现)（前提是可以修改链表）
    //-》2.利用栈（C++较简单）
    //-》3.利用递归，栈即递归思想

//第一种方法会改变链表本来的顺序，后面两种只是打印对原链表并无影响

#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

//以不带头不带环的单链表为例
typedef struct LinkNode
{
    DataType data;
    struct LinkNode* next;
}LinkNode;

void LinklistInit(LinkNode** head)//初始化
{
    *head = NULL;
}

LinkNode* CreateNewNode(DataType x)//创建新节点
{
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void LinklistPushFront(LinkNode** head, DataType x)//插入新节点(头插)
{
    if(head == NULL)//非法输入
        return;
    //链表是否为空，都适用下面的情况
    LinkNode* new_node = CreateNewNode(x);
    new_node->next = *head;
    *head = new_node;
    return;
}

void PrintList(LinkNode* head)
{
    if(head == NULL)//空链表
        return;
    LinkNode* cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


//(1)改变链表的指向，实现从尾到头打印链表
void LinklistReverse1(LinkNode** head)
{
    if(head == NULL)//非法输入
        return;
    if(*head == NULL)//空链表
        return;
    LinkNode* cur  = *head;
    //通过依次将首元素结点之后的节点头插实现
    while(cur->next != NULL)
    {
        LinkNode* nex = cur->next;
        cur->next = nex->next;
        nex->next = *head;
        *head = nex;
    }
    return;
}


//(2)利用栈/递归原理从尾到头打印链表
void LinklistReverse2(LinkNode* head)
{
    if(head == NULL)//空链表
        return;
    LinklistReverse2(head->next);
    printf("%d ", head->data);
}

void Test()
{
    LinkNode* head;
    LinklistInit(&head);
    LinklistPushFront(&head, 2);
    LinklistPushFront(&head, 3);
    LinklistPushFront(&head, 4);
    LinklistPushFront(&head, 5);
    LinklistPushFront(&head, 6);
    LinklistPushFront(&head, 7);
    PrintList(head);
    LinklistReverse2(head);
    printf("\n");
    LinklistReverse1(&head);
    PrintList(head);
}

int main()
{
    Test();
    return 0;
}
