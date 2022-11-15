struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    if(pListHead == NULL)
        return pListHead;

    struct ListNode*fast = pListHead;
    struct ListNode*slow = pListHead;

    //fast先走k步
    while(k--)
    {
        if(fast ==NULL)
        return NULL;
        fast = fast->next;
    }

    //fast和slow同时走
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}