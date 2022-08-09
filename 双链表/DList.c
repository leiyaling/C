#include "DList.h"
DLTNode* DListInit()
{
	//哨兵位头节点
	DLTNode* phead = (DLTNode * )malloc(sizeof(DLTNode));
	if (phead ==NULL)
		exit(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}
 DLTNode* BuyListNode(DLTDataType x)
 {
	 DLTNode* newnode = (DLTNode*)malloc(sizeof(DLTNode));
	 if (newnode == NULL)
	 {
		 printf("%s\n", "内存分配不成功");
		 exit(-1);
	 }
	 newnode->data = x;
	 newnode->prev = NULL;
	 newnode->next = NULL;
	 return newnode;
 }
 void DListPrintf(DLTNode* phead)
 {
	 assert(phead);
	 DLTNode* cur = phead->next;
	 while (cur!=phead)
	 {
		 printf("%d  ", cur->data);
		 cur = cur->next;
	 }
	 printf("\n");
 }
 void DListPushBack(DLTNode* phead, DLTDataType x)
 {	
	 assert(phead);
	 /*DLTNode* tail=phead->prev;
	 DLTNode* newnode = BuyListNode(x);

	 tail->next = newnode;
	 newnode->prev =tail;
	 newnode->next = phead;
	 phead->prev = newnode;*/
	 DListInsert(phead, x);
	 
 }
 void DListPopBack(DLTNode* phead)
 {
	 assert(phead);
	 assert(phead->next != phead);
	 DLTNode* tail = phead->prev;
	 DLTNode* prevtail = tail->prev;
	 free(tail);
	 prevtail->next = phead;
	 phead->prev = prevtail;
	 


 }
 void DListPushFront(DLTNode* phead, DLTDataType x)
 {
	 assert(phead);
	 /*DLTNode* newnode = BuyListNode(x);
	 DLTNode* next = phead->next;
	 phead->next = newnode;
	 newnode->prev = phead;
	 newnode->next = next;
	 next->prev = newnode;*/
	 DListInsert(phead->next, x);
 }
 void DListPopFront(DLTNode* phead) {
	 assert(phead);
	 assert(phead->next != phead);
	 DLTNode* next = phead->next;
	 DLTNode* nextNext= next->next;
	 phead->next = nextNext;
	 nextNext->prev = phead;
	 free(next);

 }
 DLTNode* DListFind(DLTNode* phead, DLTDataType x)
 {
	 assert(phead);
	 DLTNode* cur = phead->next;
	 while (cur != phead)
	 {
		 if (cur->data == x)
		 {
			 return cur;
		}
		 else 
		 {
			cur = cur->next;
		 } 
	 }
	 return NULL;
 }
 //pos位置之前插入
 void DListInsert(DLTNode* pos, DLTDataType x)
 {
	 assert(pos);
	 DLTNode* posPrev = pos->prev;
	 DLTNode* newnode = BuyListNode(x);
	 posPrev->next = newnode;
	 newnode->prev = posPrev;
	 newnode->next = pos;
	 pos->prev = newnode;
	 
 }
 void DListErase(DLTNode* pos)
 {
	 DLTNode* posPrev = pos->prev;
	 DLTNode* posNext = pos->next;

	 posPrev->next = posNext;
	 posNext->prev = posPrev;
	 free(pos);
 }
 DLTNode* DListDestroy(DLTNode* phead)
 {
	 assert(phead);
	 DLTNode* cur = cur->next;
	 while (cur != phead)
	 {
		 DLTNode* next = cur->next;
		 free(cur);
		 cur = next;
	 }
	 free(phead);
	 phead = NULL;
 }