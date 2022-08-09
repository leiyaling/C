#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DLTDataType;
typedef struct DLTNode {
	DLTDataType data;
	struct DLTNode* prev;
	struct DLTNode* next;
}DLTNode;

DLTNode* DListInit();
DLTNode* DListDestroy(DLTNode* phead);
DLTNode* BuyListNode(DLTDataType x);
void DListPrintf(DLTNode* phead);
void DListPushBack(DLTNode* phead,DLTDataType x);
void DListPopBack(DLTNode* phead);
void DListPushFront(DLTNode* phead, DLTDataType x);
void DListPopFront(DLTNode* phead);
DLTNode* DListFind(DLTNode* phead, DLTDataType x);
void DListInsert(DLTNode* pos, DLTDataType x);
void DListErase(DLTNode* pos);
