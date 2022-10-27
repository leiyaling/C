struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL)
        return head;
     struct ListNode *odd=head;
     struct ListNode *evenhead=head->next;
     struct ListNode *even=evenhead;
     while(even != NULL && even->next != NULL)
     {
         odd->next = even->next;
         odd = odd->next;
         even->next = odd->next;
         even = even->next;
     }
     odd->next = evenhead;
    return head;

}