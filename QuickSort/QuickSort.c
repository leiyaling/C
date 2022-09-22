#include"Sort.h"
#include "Stack.h"


//快排最好的情况：key值为中位数
//快排的缺陷：当数组接近有序或有序时  时间复杂度--->O(N^2)-----最坏情况
// 解决快排中有序问题
//   三数取中----左边  中间   右边   取三个数中不是最大的也不是最小的那一个做key
// 面对有序最坏的情况 ，选中位数做key，变成最好的情况，优化性能
// 递归深度太深会导致栈溢出

int GetMidIndex(int* arr, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + ((right - left) >> 1);
	if (arr[left] > arr[mid])
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[left] < arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//arr[left] < arr[mid]
	{
		if (arr[mid] < arr[right])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//O(N)
int Partion1(int* arr, int left, int right)
{
	//左边的值做key
	//右边的先走，找比key小的值,找到后停下来
	//左边的后走，找比key大的值,找到后停下来
	//左边和右边交换
	//交换后继续走直到左边和右边相遇
	//2 2 2 2 2 2 2 2  ---->需要控制边界，right可能会越界


	//三数取中
	int mini = GetMidIndex(arr, left, right);
	Swap(&arr[mini], &arr[left]);



	int keyi = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[keyi])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[left]);
	return left;
}
//挖坑法
int Partion2(int* arr, int left, int right)
{
	//三数取中
	int mini = GetMidIndex(arr, left, right);
	Swap(&arr[mini], &arr[left]);

	int key = arr[left];
	int pivot = left;
	while (left < right)
	{
		//右边找小，放到左边的坑里面
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		arr[pivot] = arr[right];
		pivot = right;
		//左边找到大，放到右边的坑里面
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		arr[pivot] = arr[left];
		pivot = left;
	}
	arr[pivot] = key;
	return pivot;
}
//双指针法----前后指针
//cur找到比key小的值就停下来  ++prev  交换prev和cur位置的值(cur找小，把小的往左边翻，prev把大的序列往右边推)          
//prev要么紧跟着cur  要么紧跟着比key要大的序列
int Partion3(int* arr, int left, int right)
{
	//三数取中
	int mini = GetMidIndex(arr, left, right);
	Swap(&arr[mini], &arr[left]);

	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
		/*while (cur <= right && arr[cur] >= arr[keyi])
		{
			++cur;
		}
		if (cur <= right)
		{
			Swap(&arr[cur], &arr[prev]);
			++cur;
		}*/
	}
	Swap(&arr[keyi], &arr[prev]);
	return prev;
}
//递归实现快速排序O(N*logN)
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化,当分割到小区间时，不再用递归分割的思路让这段子区间有序
	//对于递归快排，减少递归次数
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else
	{
		int keyi = Partion3(arr, left, right);
		//[left,keyi] keyi [keyi+1,right]
		QuickSort(arr, left, keyi - 1);
		QuickSort(arr, keyi + 1, right);
	}
	
}
//非递归实现快速排序O(N*logN)-----使用栈实现
void QuickSortNonR(int* arr, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int keyi = Partion3(arr, begin, end);
		//[begin,keyi] keyi [keyi+1,end]
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}

		if (begin < keyi - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}


	StackDestroy(&st);

}