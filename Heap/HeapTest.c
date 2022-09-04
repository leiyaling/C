#include "Heap.h"
//在N个数找出最大的前K个  or  在N个数找出最小的前K个  
void PrintTopK(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	//创建一个K个数的小堆
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}
	//剩下的N-K个数跟堆顶的数据比较，比它大，就替换掉它进堆
	for (int i = k; i < n; ++i)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
	HeapDistroy(&hp);
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}

	//设置10个比100万大的数
	a[5] = 1000000 + 1;
	a[52] = 1000000 + 2;
	a[1665] = 1000000 + 3;
	a[589] = 1000000 + 4;
	a[677] = 1000000 + 5;
	a[588] = 1000000 + 6; 
	a[1095] = 1000000 + 7;
	a[4565] = 1000000 + 8;
	a[665] = 1000000 + 9;
	a[85] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
//升序
void HeapSort(int* a, int n)
{
	//把a构建成小堆
	//方法一
	/*for (int i = 1; i < n; ++i)
	{
		AdjustUp(a, i);
	}*/
	//方法二
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);

	}
	//依此选数，调堆
	//O(N*logN)
	//for (int end = n - 1; end > 0; --end)
	//{
	//	Swap(&a[end], &a[0]);

	//	//再调堆，选出次小的数
	//	AdjustDown(a, end, 0);
	//}
}
int main()
{
	//TestTopk();

	int a[] = { 70,56,30,25,15,10,75,33,50,69 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	/*HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		HeapPush(&hp,a[i]);
	}
	HeapPrint(&hp);


	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDistroy(&hp);*/
	return 0;
}