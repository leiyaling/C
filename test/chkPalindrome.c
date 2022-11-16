//找到链表的中间节点
    ListNode* middleNode(ListNode* pHead){
        ListNode* fast,*slow = pHead;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    //翻转后面的链表
    ListNode* reverseList(ListNode* head){
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
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* middleHead = middleNode(A);
        ListNode* reverseHead = reverseList(middleHead);
        while(A && middleHead){
            if(A->val != reverseHead->val)
                return false;
            A = A->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }