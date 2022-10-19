struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    
    struct ListNode* cur1=list1;
    struct ListNode* cur2=list2;
    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    if(cur1->val<cur2->val)
    {
        head=cur1;
        cur1=cur1->next;
    }
    else
    {
        head=cur2;
        cur2=cur2->next;
    }
    tail=head;
    while(cur1 &&cur2)
    {
        if(cur1->val<cur2->val)
        {
            tail->next=cur1;
            tail=tail->next;
            cur1=cur1->next;
            
        }
       else
        {
            tail->next=cur2;
            tail=tail->next;
            cur2=cur2->next;
        } 
    }
    if(cur1==NULL)
        tail->next=cur2;
    else
        tail->next=cur1;
        
    return head;

}