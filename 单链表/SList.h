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
//��������ڵ�
void SListPushBack(SLTNode** pphead,SLTDataType x);
//����ǰ����ڵ�
void SListPushFront(SLTNode** pphead, SLTDataType x);
//�����ɾ���ڵ�
void SListPopBack(SLTNode** pphead);
//����ǰɾ���ڵ�
void SListPopFront(SLTNode** pphead);
//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��posλ��֮ǰ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��posλ��֮ǰ����һ���ڵ�
void SListInsertAfter(SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pphead, SLTNode* pos);
void SListDestory(SLTNode** pphead);
//void SListInsert(SLTNode**pphead, int pos, SLTDataType x);