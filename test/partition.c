ListNode* partition(ListNode* pHead, int x) {
        struct ListNode *lessHead,*greaterHead,*lessTail,*greaterTail;

        //开一个哨兵位的头节点，方便尾插
        lessHead=lessTail=(struct ListNode*)malloc(sizeof(struct ListNode));
        lessTail->next=NULL;

        greaterHead=greaterTail=(struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail->next=NULL;

        struct ListNode*cur= pHead;
        while(cur)
        {
            if(cur->val<x)
            {
                lessTail->next=cur;
                lessTail=cur;
            }
            else{
                greaterTail->next=cur;
                greaterTail=cur;
                
            }
            cur=cur->next;  
        }
        lessTail->next=greaterHead->next;
        greaterTail->next=NULL;//如果不将偏大的链表置为空，可能会形成环

        struct ListNode*listHead=lessHead->next;
        free(lessHead);
        free(greaterHead);
        return listHead;

    }