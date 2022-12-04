void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child +1 < n && a[child] < a[child + 1])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//从最后一个非叶子节点开始调
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
		
	
	
}