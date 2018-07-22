//实现以O(1)时间复杂度删除链表结点

#include <stdio.h>
#include <stdlib.h>

//这里实现不带头不带环的单链表
typedef struct LinkNode
{
    int val;
    struct LinkNode* next;
}LinkNode;

void LinklistInit(LinkNode** head)
{
    *head = NULL;
}

LinkNode* CreateNewNode(int value)
{
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

void LinklistInsert(LinkNode** head, LinkNode* pos, int value)//在pos位置之前插入元素
{
    if(head == NULL)
        return;
    if(*head == pos)//插入的pos节点即为头结点
    {
        LinkNode* new_node = CreateNewNode(value);
        new_node->next = pos;
        *head = new_node;
        return;
    }
    LinkNode* cur = *head;//插入的pos不是链表的头结点
    for(; cur!=NULL; cur=cur->next)
    {
        if(cur == pos)
            break;
    }
    if(cur == NULL)//没找到pos节点
        return;
    LinkNode* new_node = CreateNewNode(value);
    new_node->next = pos->next;
    pos->next = new_node;
    return;
}

void Print(LinkNode* head)
{
    if(head == NULL)//空链表
        return;
    LinkNode* cur = head;
    for(; cur!=NULL; cur=cur->next)
    {
        printf("%d ", cur->val);
    }
    printf("\n");
}

//解法:将pos位置的值赋值给它的下一个节点，再删除下一个节点，就可以实现O(1)的时间复杂度
//这里实现的代码建立在pos一定在链表中存在
    //-》虽然这里在删除尾节点的时候，O(n)时间复杂度，但是总的来讲这个函数的平均时间复杂度是[(n-1)*O(1)+O(n)]/n=O(1)
void LinklistErase(LinkNode** head, LinkNode* pos)
{
    if(head == NULL)
        return;
    if(*head == NULL)
        return;
    //(1)要删除的链表只有一个节点，且为pos节点
    if((*head)->next == NULL && *head == pos)
    {
        free(*head);
        *head = NULL;
        return;
    }
    //(2)要删除的链表不只一个节点，且pos存在
    else if(pos->next != NULL)
    {
        LinkNode* nex = pos->next;
        pos->val = nex->val;
        pos->next = nex->next;
        free(nex);
    }
    //(3)链表不只一个节点，且pos是链表的最后一个节点
    else
    {
        LinkNode* cur = *head;
        LinkNode* pre = NULL;
        while(cur!=NULL)
        {
            if(cur != pos)
            {
                pre = cur;
                cur = cur->next;
            }
            else
                break;
        }
        pre->next = pos->next;
        free(pos);
        return;
    }
}

void Test()
{
    LinkNode* head;
    LinklistInit(&head);
    LinklistInsert(&head, head, 1);
    LinklistInsert(&head, head, 2);
    LinklistInsert(&head, head->next, 3);
    LinklistInsert(&head, head, 4);
    LinklistInsert(&head, head, 5);
    Print(head);
    LinklistErase(&head, head);
    Print(head);
    LinklistErase(&head, head->next);
    Print(head);
    LinklistErase(&head, head->next->next);
    Print(head);
}

int main()
{
    Test();
    return 0;
}
