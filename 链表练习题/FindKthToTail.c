#include<stdio.h>
#include<assert.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead,int k)
{	
	assert(pListHead);
	struct ListNode* fast, *slow;
	fast = slow = pListHead;
	while (k--)
	{
		//k大于链表的长度
		if (fast)
		{
			return NULL;
		}
			
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}