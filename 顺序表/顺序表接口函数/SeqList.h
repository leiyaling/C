#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SeqDatatype;
typedef struct SeqList {
	SeqDatatype* a;
	int size;
	int capacity;
}SL;
void SeqListInit(SL* ps);
void SeqListPrint(SL*ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SeqDatatype* x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SeqDatatype* x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SeqDatatype* x);
void SeqListInsert(SL* ps, int pos, SeqDatatype* x);
void SeqListErase(SL* ps, int pos);
void SeqListDestroy(SL* ps);
