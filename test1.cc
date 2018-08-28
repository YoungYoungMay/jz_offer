//删除链表中重复的结点
    //重复的结点不保留，只保留出现一次的结点

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead==NULL || pHead->next==NULL)//空链表或只有一个结点
        return pHead;
    ListNode* pre = NULL;
    ListNode* cur = pHead;
    ListNode* nxt = NULL;
    while(cur != NULL)
    {
        //当前结点即为重复结点
        if(cur->next!=NULL && cur->val==cur->next->val)
        {
            nxt = cur->next;
            //找到不重复的下一个结点
            while(nxt!=NULL && nxt->next!=NULL && nxt->val==nxt->next->val)
                nxt = nxt->next;
            //走到这里时nxt的下一个才是不重复的结点
            //若当前重复结点是pHead
            if(cur == pHead)    
                pHead = nxt->next;
            else
                pre->next = nxt->next;
            //将接下来要处理的结点向后移动
            cur = nxt->next;    
        }
        //当前结点不重复
        else
        {
            pre = cur;
            cur = cur->next;                             
        }
    }
    return pHead;
}
