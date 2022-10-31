struct ListNode* removeElements(struct ListNode* head, int val) {
   /* if (head == NULL) {
        return head;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;*/

if(head == NULL)
        return head;

    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;
    struct ListNode*cur =head;
    struct ListNode*prev =newhead;
    while(cur)
    {

        if(cur->val == val)
        {
            prev->next = cur->next;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;

        }
    }
    return newhead->next;
}



