#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};
//��ת����ͷ�壩
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* newnode = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		//ͷ��
		cur->next = newnode;
		newnode = cur;
		//����������
		cur = next;
	}
	return newnode;
}
