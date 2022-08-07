#include "SList.h" 
SLTNode* BuyListNode(SLTDataType x) 
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("%s\n", "内存分配不成功");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;

}
void SListPrint(SLTNode* phead) 
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur != NULL) 
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void SListPushBack(SLTNode** pphead, SLTDataType x) 
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	
	if (*pphead == NULL) 
	{
		*pphead = newnode;
	}
	else 
	{
		//找到尾节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL) 
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
	
	
}
void SListPushFront(SLTNode** pphead, SLTDataType x) 
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;
	}
	//assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		//while (tail->next!= NULL)
		while(tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
	prev->next = NULL;
	}
	
	 
	/*SLTNode* tail = *pphead;
	while (tail->next->next)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;*/
}
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead=next;
}
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//在pos位置之后去插入一个节点(更适合单链表，更简单)  O(1)
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	 newnode->next=pos->next ;
	 pos->next = newnode;
}
//在pos位置之前去插入一个节点 O(n)
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
	
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	if (*pphead == pos)
	{
		/* *pphead = pos->next;
		free(pos);*/
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
void SListEraseAfter(SLTNode* pphead, SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	//next = NULL;
}
void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead == NULL;
}