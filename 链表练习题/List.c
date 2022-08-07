#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};
//翻转链表（头插）
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* newnode = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		//头插
		cur->next = newnode;
		newnode = cur;
		//迭代往后走
		cur = next;
	}
	return newnode;
}
