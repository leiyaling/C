#include"Sort.h"

TestQuickSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	QuickSort(a, 0,size-1);
	Print(a, size);
}
TestQuickSortNonR()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	QuickSortNonR(a, 0, size - 1);
	Print(a, size);
}
int main()
{
	
	//TestQuickSort();
	TestQuickSortNonR();

	return 0;
}