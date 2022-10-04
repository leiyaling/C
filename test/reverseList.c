
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)
        return NULL;
    struct ListNode*n1=NULL;
    struct ListNode*n2=head;
    struct ListNode*n3=head->next;

    while(n2)
    {
        //翻转
        n2->next=n1;
        //迭代往后走
        n1=n2;
        n2=n3;
        if(n3)
             n3=n3->next;
    }
    return n1;
}

struct ListNode* reverseList(struct ListNode* head){
   
    struct ListNode*newhead=NULL;
    struct ListNode*cur=head;
    

    while(cur)
    {
        struct ListNode*next=cur->next;
        //头插
        cur->next=newhead;
        newhead=cur;
        //迭代往后走
        cur=next;
    }
    return newhead;
}