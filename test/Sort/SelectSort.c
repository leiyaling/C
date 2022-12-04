void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
			{
				if (a[i] > a[max])
					max = i;
				if (a[i] < a[min])
					min = i;
			}
		Swap(&a[begin], &a[min]);
		//begin = max时，最大值被换走了，需要修正max的位置
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
	
}