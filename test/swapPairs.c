struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode* newHead = head->next; 
    struct ListNode* tmpHead = swapPairs(newHead->next);
    head->next = tmpHead;
    newHead->next = head;
    return newHead;
    
}