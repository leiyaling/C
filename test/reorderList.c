//找到原链表的中点
//将原链表的右半端反转
//将原链表的两端合并。

struct ListNode* middleNode(struct ListNode*head)
{
    struct ListNode* fast, *slow;
	fast = slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

struct ListNode* reverseList(struct ListNode* head){
   struct ListNode *cur = head; 
   
   struct ListNode *newhead=NULL;
   while(cur)
   { 
        struct ListNode *next=cur->next;
        cur->next = newhead;
        newhead=cur;
        cur =next;
   }
  return newhead;
}
void mergeList(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1_tmp;
    struct ListNode* l2_tmp;
    while (l1 != NULL && l2 != NULL) {
        l1_tmp = l1->next;
        l2_tmp = l2->next;

        l1->next = l2;
        l1 = l1_tmp;

        l2->next = l1;
        l2 = l2_tmp;
    }
}

void reorderList(struct ListNode* head){
    if(head==NULL)
        return ;
    struct ListNode *mid=middleNode(head);
    struct ListNode* l1 = head;
    struct ListNode* l2 = mid->next;
    mid->next = NULL;
    l2=reverseList(l2);
    mergeList(l1,l2);
   
}