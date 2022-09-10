#include"Sort.h"

void Print(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ʱ�临�Ӷ� ��O(N^2)
//��ã�O(N) --˳��������߽ӽ�����
//���O(N^2) --����
//�ռ临�Ӷȣ�O(1��
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{

		//��x������������[0��end]
		int end = i;
		int x = arr[end + 1];//��end+1��x������������֤���ᱻ���ǵ�
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
//ϣ������O(N^1.3)
//��gap��������ݽ���Ԥ����
//gapԽ��Ԥ��Խ�죬Ԥ�ź�Խ���ӽ�����
//gapԽС��Ԥ��Խ����Ԥ�ź�Խ�ӽ�����

void ShellSort(int* arr, int n)
{
	//���Ԥ����(gap>1)+ֱ�Ӳ���(gap=1)
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap���һ���ܵ�1
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
//ѡ������
void SelectSort(int* arr, int n)
{
	int begin = 0,end = n - 1;
	//ʹ���±��Ǳ���һ�������ֵ����Сֵ
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
		//begin = maxʱ�����ֵ�������ˣ���Ҫ����max��λ��
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
//������
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