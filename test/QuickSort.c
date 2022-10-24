int GetMidIndex(int* a, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
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
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
int Partion(int* a,int left,int right)
{
	//三数取中
	int m = GetMidIndex(a, left, right);
	Swap(&a[m], &a[left]);

	int keyi = left;
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])//防止特殊情况
			right--;

		//左边再走，找大
		while (left < right && a[left] <= a[keyi])
			left++;
		
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
//挖坑法
int Partion2(int* a, int left, int right)
{
	//三数取中
	int mini = GetMidIndex(a, left, right);
	Swap(&a[mini], &a[left]);

	int key = a[left];
	int pivot = left;
	while (left < right)
	{
		//右边找小，放到左边的坑里面
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[pivot] = a[right];
		pivot = right;
		//左边找到大，放到右边的坑里面
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[pivot] = a[left];
		pivot = left;
	}
	a[pivot] = key;
	return pivot;
}
//前后指针法
int Partion3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int *a,int left,int right)
{
	if (left >= right)
		return;

	int keyi = Partion3(a, left, right);
	//[left, keyi - 1] keyi [keyi + 1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}