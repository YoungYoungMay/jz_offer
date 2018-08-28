//求链表中环的入口结点

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == NULL)
        return NULL;
    //找相遇点
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    ListNode* meet_node = NULL;
    while(fast!=NULL && fast->next!=NULL && slow!=NULL)
    {
        //注意这里循环刚进来时快慢指针都指向头结点，所以不能先判断
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            meet_node = slow;
            break;                                  
        }
    }
    //没有相遇点，说明链表不带环
    if(meet_node == NULL)
        return NULL;
    //有相遇点，且相遇点到入口点 == 开始点到入口点
    slow = pHead;
    while(slow != meet_node)
    {
        slow = slow->next;
        meet_node = meet_node->next;                     
    }
    return slow;
}
