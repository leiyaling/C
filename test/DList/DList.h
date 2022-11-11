#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int DListDataType;
typedef struct DListNode
{
	DListDataType* data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

DListNode* BuyListNode(DListDataType x);
void LTPrint(DListNode* phead);
DListNode* LTInit();
void LTPushBack(DListNode* phead, DListDataType x);
void LTPopBack(DListNode* phead);

void LTPushFront(DListNode* phead, DListDataType x);
void LTPopFront(DListNode* phead);
DListNode* LTFind(DListNode* phead, DListDataType x);

// posλ��֮ǰ����
void LTInsert(DListNode* pos, DListDataType x);
// posλ��֮�����
void LTErase(DListNode* pos);

bool LTEmpty(DListNode* phead);
size_t LTSize(DListNode* phead);
void LTDestroy(DListNode* phead);



