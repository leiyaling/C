#include "SList.h"

void ListTest1() 
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
}
void ListTest2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SListPopBack(&plist);

	SListPrint(plist);
}
void ListTest3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist); 
	SListPopFront(&plist);
	SListPrint(plist);
}
void ListTest4()
{
	SLTNode* plist = NULL;
	
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);

	//查找
	SLTNode* pos = SListFind(plist, 2);
	int i=1;
	while (pos)
	{
		printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	//修改 3->30
	pos = SListFind(plist, 3);
	if (pos)
		pos->data = 30;
	SListPrint(plist);
}
void ListTest5()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);

	 pos = SListFind(plist, 4);
	if (pos)
	{
		SListInsert(&plist, pos, 40);
	}
	SListPrint(plist);
}
int main() 
{
	//ListTest1();
	//ListTest2();
	//ListTest3();
	//ListTest4();
	ListTest5();
	return 0;
}
