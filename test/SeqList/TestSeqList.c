#include "SeqList.h"

int main()
{
	SeqList q;
	SeqListInit(&q);
	SeqListPushBack(&q,1);
	SeqListPushBack(&q,2);
	SeqListPushBack(&q,3);
	SeqListPrint(&q);
	SeqListPushFront(&q, 1);
	SeqListPushFront(&q, 2);
	SeqListPushFront(&q, 3);
	SeqListPushFront(&q, 4);
	SeqListPushFront(&q, 5);
	SeqListPrint(&q);
	SeqListPopBack(&q);
	SeqListPopBack(&q);
	SeqListPopBack(&q);
	SeqListPrint(&q);
	SeqListPopFront(&q);
	SeqListPopFront(&q);
	SeqListPrint(&q);
	int i=SeqListFind(&q, 1);
	if (i != -1)
	{
		printf("找到了，下标为：%d\n",i);
	}
	else
	{
		printf("没找到");
	}
	SeqListInsert(&q, 2, 20);
	SeqListPrint(&q);
	SeqListErase(&q, 2);
	SeqListPrint(&q);
	SeqListDestroy(&q);
	return 0;
}