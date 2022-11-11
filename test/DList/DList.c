#include "DList.h"

DListNode* BuyListNode(DListDataType x)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}
DListNode* LTInit()
{
	DListNode* phead = BuyListNode(-1);//头节点的data可以为任意值
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void LTPrint(DListNode* phead)
{
	assert(phead);

	DListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void LTPushBack(DListNode* phead, DListDataType x)
{
	assert(phead);
	//DListNode* newnode = BuyListNode(x);
	//DListNode* tail = phead->prev;//保存尾节点（头节点的prev）

	//tail->next = newnode;
	//newnode->prev = tail;

	//newnode->prev = phead;
	//phead->prev = newnode;

	LTInsert(phead, x);
	
}
void LTPopBack(DListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);  // 判断是否为空

	//DListNode* tail = phead->prev;

	//tail->prev->next = phead;
	//phead->prev = tail;
	//free(tail);

	LTErase(phead->prev);
}

void LTPushFront(DListNode* phead, DListDataType x)
{
	assert(phead);
	/*DListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;*/
	
	LTInsert(phead->next, x);

}
void LTPopFront(DListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);  // 判断是否为空

	//DListNode* pheadnext = phead->next;

	//phead->next = pheadnext->next;
	//pheadnext->next->prev = phead;
	//free(pheadnext);
	LTErase(phead->next);
}
DListNode* LTFind(DListNode* phead, DListDataType x)
{
	assert(phead);
	DListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// pos位置之前插入
void LTInsert(DListNode* pos, DListDataType x)
{
	assert(pos);
	DListNode* prevpos = pos->prev;
	DListNode* newnode = BuyListNode(x);
	// prev newnode pos
	prevpos->next = newnode;
	newnode->prev = prevpos;
	newnode->next = pos;
	pos->prev = newnode;
}
// 删除pos位置
void LTErase(DListNode* pos)
{
	assert(pos);
	DListNode* prevpos = pos->prev;
	DListNode* nextpos = pos->next;

	free(pos);
	prevpos->next = nextpos;
	nextpos->prev = prevpos;

}

bool LTEmpty(DListNode* phead)
{
	assert(phead);

	/*if (phead->next == phead)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return phead->next == phead;
}
size_t LTSize(DListNode* phead)
{
	assert(phead);

	size_t size = 0;
	DListNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}

	return size;
}
void LTDestroy(DListNode* phead)
{
	assert(phead);

	DListNode* cur = phead->next;
	while (cur != phead)
	{
		DListNode* next = cur->next;
		free(cur);

		cur = next;
	}
	free(phead);
}