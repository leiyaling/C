bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head,*slow = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow)
            return true;
    }
    return false;
}