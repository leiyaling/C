#include"DList.h"

void DListTest1()
{
	DLTNode* plist =DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrintf(plist);
	DListPopBack(plist);
	DListPrintf(plist);
}
void DListTest2()
{
	DLTNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrintf(plist);

	DLTNode* pos = DListFind(plist, 2);
	if (pos)
	{
		DListErase(pos);
	}
	DListPrintf(plist);
	//DListInsert(pos, 20);
	//DListPrintf(plist);
	
}
void DListTest3()
{
	DLTNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrintf(plist);
	DListDestroy(plist);
	plist = NULL;
	DListPrintf(plist);
}
int main()
{
	//DListTest1();
	DListTest2();
	return 0;
}