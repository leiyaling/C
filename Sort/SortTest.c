#include"Sort.h"
TestInsertSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	InsertSort(a, size);
	Print(a, size);
}
TestShellSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	ShellSort(a, size);
	Print(a, size);
}
TestSelectSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	SelectSort(a, size);
	Print(a, size);
}
TestHeapSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	HeapSort(a, size);
	Print(a, size);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	TestSelectSort();
	//TestHeapSort();
	return 0;
}