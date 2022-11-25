#include "Heap.h"
void TestHeap3()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(array) / sizeof(int);
	Heap hp;
	HeapCreate(&hp, array,n);
	PrintHeap(&hp);
	HeapDestroy(&hp);
}


int main()
{
	/*int a[] = { 70, 56, 30, 25, 15, 10, 75 };
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	PrintHeap(&hp);
	HeapPop(&hp);
	PrintHeap(&hp);*/
	//TestHeap3();
	TestTopk();
	return 0;
}