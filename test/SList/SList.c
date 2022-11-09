#include "SList.h"
// 动态申请一个节点
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
// 单链表打印
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
// 单链表尾插
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
// 单链表的头插
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
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	//只有一个节点时
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
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}
// 单链表查找
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
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
// 单链表的销毁
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
