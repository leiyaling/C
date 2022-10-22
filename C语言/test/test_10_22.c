#include <stdio.h>
//int main()
//{
//	int a = 6;
//	int b = 5;
//	printf("a & b=%d\n",a & b);
//	int c = 13;
//	int d = 2;
//	printf("c | d=%d\n", c | d);
//	int e = 11;
//	int f = 5;
//	printf("e ^ f=%d\n", e ^ f);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 0, a = 0, b = 2, c = 3, d = 4;
//    i = a++ && ++b && d++;
//    //i = a++||++b||d++;
//    printf(" a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);
//    return 0;
//}

//int main()
//{
//	char a = 5;
//	char b = 126;
//	char c = a + b;
//	//00000000000000000000000000000101 ---5�Ĳ���
//	//00000101  --a   �ض�֮���ֵ
//
//	//00000000000000000000000001111110 ---126�Ĳ���
//	//01111110  --b   �ض�֮���ֵ
//
//	//��������
//	//00000000000000000000000000000101 --a
//	//00000000000000000000000001111110 --b
//	//00000000000000000000000010000011
//	//10000011    --c   �ض�֮���ֵ
//
//	printf("c=%d", c);//%dʮ���Ƶ��з���λ����
//	//11111111111111111111111110000011 ����
//	//11111111111111111111111110000010 ����
//	//10000000000000000000000001111101 ԭ��
//	//-125
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(c+1));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(-c));
//	return 0;
//}

//int main()
//{
//	int arr[20] = { 1,2,3,4,5,1,2,3,4 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	for (int i = 0; i < size; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("�����ǣ�%d", ret);
//	return 0;
//}
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,1,2,3,4,9 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	for (int i = 0; i < size; i++)
//	{
//		ret ^= arr[i];
//	}
//	//ret��5��9�����ֵ
//	int pos;//5��9��λ����������е�һ����ͬ��λ��
//	for (int i = 0; i < 32; i++)
//	{
//		if ((ret >> i) & 1 == 1)
//		{
//			pos = i;
//		}
//	}
//	int sum1 = 0;
//	int sum2 = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] >> pos == 1)
//		{
//			sum1 ^= arr[i];
//		}
//		else
//		{
//			sum2 ^= arr[i];
//		}
//	}
//	printf("%d %d\n", sum1, sum2);
//	return 0;
//}
void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a,int size)
{
	for (int i = 0; i < size - 1; i++)//end�ı߽�����Ϊsize-2,end+1=size-1
	{
		int end = i;//��¼�������е����һ��Ԫ�ص��±�
		int  x= a[end + 1];//�������Ԫ��
	
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];//������������endС����end�±��ֵ����Ų
				--end;				//end--��end+1Ϊ�±�ĵط��ճ���������ѭ����ֱ���ҵ����ʵ�λ�ò���
			}
			else
			{
				break;
			}
		}
		//�����ֵ��end�±��ֵ�󣬻���end=-1��end�ߵ����������ǰ�棩����Ҫ�����ֵ�ŵ�end�ĺ���
		a[end + 1] = x;

	}
}
void ShellSort(int* a, int n)
{
	//gap>1Ԥ����  gap=1 ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}
	}
	
	
}
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py=tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;//���±��¼���ֵ����Сֵ
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[min] > a[i])
				min = i;
			if (a[max] < a[i])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		//begin = maxʱ�����ֵ�������ˣ���Ҫ����max��λ��
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		end--;

	}
	
}
void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		//ѡ�����Һ��ӽϴ��
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
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
	//�����򣬽����
	//�������(���µ����������һ����Ҷ�ӽڵ㣬���һ����Ҷ�ӽڵ������һ���ڵ�ĸ���)
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a,n ,i );
	}
	//����ѡ��������
	//O(N*logn)
	for (int end = n - 1; end > 0; --end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
	}
	

}
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				exchange = 1;
				Swap(&a[i], &a[i + 1]);
			}
		}
		if (exchange == 0)
			break;
		end--;
	}
	
}
int main()
{
	int arr[10] = { 2,8,6,4,5,9,1,7,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print(arr, size);
	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	BubbleSort(arr, size);
	Print(arr, size);
	return 0;
}