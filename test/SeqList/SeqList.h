#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;

typedef struct SeqList {
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);
void CheckCapacity(SeqList* ps);
void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);