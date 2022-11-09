#include "SList.h"
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* phead = plist;
	while (phead)
	{
		printf("%d ", phead->data);
		phead = phead->next;
	}
		printf("\n");
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next)
			tail = tail->next;
		tail->next = newnode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	//ֻ��һ���ڵ�ʱ
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		SListNode* tailprev = NULL;
		while (tail->next)
		{
			tailprev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		tailprev->next = NULL;	
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
// �����������
void SListDestroy(SListNode** pplist)
{
	SListNode* cur = *pplist;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pplist = NULL;
}
