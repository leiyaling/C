// 冒泡排序
void BubbleSort(int* a, int n)
{
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				Swap(&a[j], &a[j + 1]);
			}
				
		}
		if (!flag)
			break;
	}
}