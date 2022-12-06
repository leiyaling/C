// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	
	while (left < right)
	{
		//右边先走，找比keyi小的值
		while (left < right && a[right] >= a[keyi])
			right--;
		//左边走，找比keyi大的值
		while (left < right && a[left] <= a[keyi])
			left++;
		
		//交换
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	keyi = left;
	return keyi;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int keyi = a[left];
	int hole = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
			end--;
		a[hole] = a[end];
		hole = end;

		while (begin < end && a[begin] <= keyi)
			begin++;
		a[hole] = a[begin];
		hole = begin;
		
	}
	a[hole] = keyi;
	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <  a[keyi] && a[++prev] != a[cur])
		{
			Swap(&a[prev], &a[cur]);
		}	
		cur++;
		
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = PartSort2(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}