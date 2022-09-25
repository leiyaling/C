//递归实现归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	// [left, mid] [mid+1, right] 有序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// tmp 数组拷贝回a
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

//非递归实现归并排序
// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 核心思想：end1、begin2、end2都有可能越界
			// end1越界 或者 begin2 越界都不需要归并
			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			// end2 越界，需要归并，修正end2
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
				{
					tmp[index++] = arr[begin1++];
				}
				else
				{
					tmp[index++] = arr[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[index++] = arr[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[index++] = arr[begin2++];
			}

			// 把归并小区间拷贝回原数组
			for (int j = i; j <= end2; ++j)
			{
				arr[j] = tmp[j];
			}
		}

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}


//时间复杂度：O(Max(N,Range))
//空间复杂度：O(Range)
//适合范围比较集中的整数数组  范围较大，或者是浮点数等都不适合排序
void CountSort(int* arr, int n)
{
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if(arr[i]<min)
			min = arr[i];
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0; i < n; ++i)
	{
		count[arr[i] - min]++;
	}
	//根据次数，进行排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			arr[j++] = i + min;
		}
	}

}