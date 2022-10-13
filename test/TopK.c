#include<stdio.h>
#include<stdlib.h>

//Topk问题
void PrintTopK(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	//前K个数建立小堆
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);
	}
	//N-K 个数依次和堆顶的数据比较
	for (int i = k; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);

			//hp.a[0] = a[i];
			//AdjustDown(hp.a,hp.size,0);

		}
	}
	HeapPrint(&hp);
	HeapDestory(&hp);
	
}
void TestTopk()
{
	int n = 1000000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	// 再去设置10个比100w大的数
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[5355] = 1000000 + 3;
	a[51] = 1000000 + 4;
	a[15] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
int main()
{
	TestTopk();
	return 0;
}