#include "Heap.h"

void Swap(HPDataType* px, HPDataType* py)
{
	HPDataType tmp = *px;
	*px = *py;
	*py = tmp;
}
void PrintHeap(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;

}
//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向下调整
void AdjustDown(HPDataType* a,int parent, int n)
{
	int child = 2 * parent + 1;
	
	while (child < n)
	{
		
		// 确认child指向大的那个孩子
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child= 2 * parent + 1;
		}
		else
		{
			break;
		}
		
	}
}
// 堆的构建
//void HeapCreate(Heap* php, HPDataType* a, int n)
//{
//	assert(php);
//	HeapInit(php);
//	for (int i = 0; i < n; ++i)
//	{
//		HeapPush(php, a[i]);
//	}
//}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(hp->a, a, sizeof(HPDataType) * n);
	hp->size = hp->capacity = n;


	// 建堆算法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->a, i, n);
	}
}
// 堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->capacity = hp->size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	assert(hp);
	if (hp->size == hp->capacity)
	{
		size_t newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;
	AdjustUp(hp->a, hp->size - 1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	//删除堆顶的数据，然后调整
	assert(!HeapEmpty(hp));

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, 0, hp->size);

}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
void PrintTopK(int* a, int n, int k)
{
	Heap hp;

	//前K个数建立小堆
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);
	}
	//N-K 个数依次和堆顶的数据比较
	for (int i = k; i < n; i++)
	{
		if (a[i] > a[0])
		{
			Swap(&a[i], &a[0]);
			a[0] = a[i];
			AdjustDown(a,0,k);
		}
	}
}
void TestTopk()
{
	int n = 1000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000;
	}
	// 再去设置10个比100w大的数
	a[5] = 1000000 + 1;
	a[123] = 1000000 + 2;
	a[535] = 1000000 + 3;
	a[51] = 1000000 + 4;
	a[15] = 1000000 + 5;
	a[233] = 1000000 + 6;
	a[999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[314] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
void HeapSort(int* a, int n)
{
	//构建大堆（向上调整，从第二个节点开始）
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	 }*/
	 //构建大堆(向下调整，从最后一个非叶子节点，最后一个非叶子节点是最后一个节点的父亲)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//依次选数，调堆
	for (int end = n - 1; end > 0; end--)
	{
		Swap(&a[end], &a[0]);
		//再调堆，选出次小的数
		AdjustDown(a, end, 0);
	}
}