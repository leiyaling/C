#include "Heap.h"
//��N�����ҳ�����ǰK��  or  ��N�����ҳ���С��ǰK��  
void PrintTopK(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	//����һ��K������С��
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}
	//ʣ�µ�N-K�������Ѷ������ݱȽϣ������󣬾��滻��������
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

	//����10����100������
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
//����
void HeapSort(int* a, int n)
{
	//��a������С��
	//����һ
	/*for (int i = 1; i < n; ++i)
	{
		AdjustUp(a, i);
	}*/
	//������
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);

	}
	//����ѡ��������
	//O(N*logN)
	//for (int end = n - 1; end > 0; --end)
	//{
	//	Swap(&a[end], &a[0]);

	//	//�ٵ��ѣ�ѡ����С����
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