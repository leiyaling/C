#include"SeqList.h"

Test1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1,1);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1, 2);
	
	SeqListPushFront(&s1,10);
	SeqListPushFront(&s1,20);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}
Test2()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 2, 30);
	int pos = SeqListFind(&s1, 4);
	if (pos != -1)
	{
		SeqListInsert(&s1, pos, 80);
	}
	SeqListPrint(&s1);
	SeqListErase(&s1,1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}
int main()
{
//	Test1();
	Test2();
	return 0;
}