#include<stdio.h>
#include<assert.h>
#include<stdio.h>

void _MerSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	//[left,mid] [mid+1,right] 有序
	_MerSort(arr, left, mid, tmp);
	_MerSort(arr, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[i++] = arr[begin1];
		else
			tmp[i++] = arr[begin2];

	}
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2];
	}
	//把归并后的数据(tmp)拷贝回原数组(arr)
	for (int j = left; j <= right; ++j)
	{
		arr[j] = tmp[j];
	}

}
//归并排序
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exiy(-1);
	}
		
	_MerSort(arr, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

TestMergeSort()
{
	int a[] = { 2,6,8,4,0,9,7,1,3,5 };
	int size = sizeof(a) / sizeof(a[0]);
	Print(a, size);
	MergeSort(a, size);
	Print(a, size);
}
int main()
{
	TestMergeSort();

	return 0;
}