#include"Sort.h"

void Print(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//时间复杂度 ：O(N^2)
//最好：O(N) --顺序有序或者接近有序
//最坏：O(N^2) --逆序
//空间复杂度：O(1）
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{

		//将x插入有序区间[0，end]
		int end = i;
		int x = arr[end + 1];//将end+1用x保存起来，保证不会被覆盖掉
		while (end >= 0)
		{
			if (arr[end] > x)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = x;
	}
	
}
//希尔排序O(N^1.3)
//按gap分组对数据进行预排序
//gap越大，预排越快，预排后越不接近有序
//gap越小，预排越慢，预排后越接近有序

void ShellSort(int* arr, int n)
{
	//多次预排序(gap>1)+直接插入(gap=1)
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap最后一定能到1
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int x = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > x)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = x;
		}
	}
	
}
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//选择排序
void SelectSort(int* arr, int n)
{
	int begin = 0,end = n - 1;
	//使用下标标记遍历一遍后的最大值、最小值
	while (begin < end)
	{
		int min = begin,max = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;		
		}
		Swap(&arr[begin], &arr[min]);
		//begin = max时，最大值被换走了，需要修正max的位置
		if (begin == max)
			max = min;
		Swap(&arr[end], &arr[max]);
		++begin;
		--end;
	}
	
}

void AdjustDown(int* arr, int n,int parent)
{
	int child = 2 * parent + 1;
	while (child > 0)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* arr, int n)
{
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}
	//O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}