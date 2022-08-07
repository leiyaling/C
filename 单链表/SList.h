#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SlistNode* next;
}SLTNode;
void SListPrint(SLTNode* phead);
//链表后插入节点
void SListPushBack(SLTNode** pphead,SLTDataType x);
//链表前插入节点
void SListPushFront(SLTNode** pphead, SLTDataType x);
//链表后删除节点
void SListPopBack(SLTNode** pphead);
//链表前删除节点
void SListPopFront(SLTNode** pphead);
//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//在pos位置之前插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//在pos位置之前插入一个节点
void SListInsertAfter(SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pphead, SLTNode* pos);
void SListDestory(SLTNode** pphead);
//void SListInsert(SLTNode**pphead, int pos, SLTDataType x);