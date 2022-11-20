struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head,*slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            slow = head;
            while(slow != fast)
            {
                fast = fast->next;
                slow = slow->next;

            }
             return fast;

        }
    }
    return NULL;
}