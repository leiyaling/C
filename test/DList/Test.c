#include "DList.h"

void TestList1()
{
	DListNode* phead = LTInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);

	LTPopBack(phead);
	LTPrint(phead);
	LTPopBack(phead);
	LTPrint(phead);
	LTPopBack(phead);
	LTPrint(phead);
	LTPopBack(phead);
	LTPrint(phead);
	LTPopBack(phead);
	LTPrint(phead);

	//LTPopBack(phead);
}

void TestList2()
{
	DListNode* phead = LTInit();
	LTPushFront(phead, 1);
	LTPushFront(phead, 2);
	LTPushFront(phead, 3);
	LTPushFront(phead, 4);
	LTPushFront(phead, 5);
	LTPrint(phead);

	LTPopFront(phead);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);
}

void TestList3()
{
	DListNode* phead = LTInit();
	LTPushFront(phead, 1);
	LTPushFront(phead, 2);
	LTPushFront(phead, 3);
	LTPushFront(phead, 4);
	LTPushFront(phead, 5);
	LTPrint(phead);

	DListNode* pos = LTFind(phead, 3);
	LTPrint(phead);

	LTDestroy(phead);
	phead = NULL;
}

int main()
{
	
	TestList1();
	//TestList2();
	//TestList3();
	return 0;
}