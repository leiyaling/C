#include<stdio.h>
#include<string.h>
void my_sort(int arr[], int size)
{

	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < size-i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
//void BubbleSort(int array[], int size)
//{
//    int i = 0;
//    int flag=0;
//    // ���ѭ������ð�����������
//    // size-1��ʾ�����һ��������ֻʣ��1��Ԫ�أ�����ð�ݿ���ʡ��
//    for (i = 0; i < size - 1; ++i)
//    {
//        // ����ð�ݵķ�ʽ�������ڵ�����Ԫ�ؽ��бȽϣ�ǰһ�����ں�һ��Ԫ��ʱ���������������ݣ�����ֱ�������ĩβ
//        for (int j = 1; j < size - i; ++j)
//        {
//            if (array[j - 1] > array[j])
//            {
//		flag=1;
//                int temp = array[j - 1];
//                array[j - 1] = array[j];
//                array[j] = temp;
//            }
//	if(flag==0)//��һ��û�н��뽻������������������ģ�����ѭ��
//	break;
//        }
//    }
//    for (i = 0; i < size; i++)
//        	{
//        		printf("%d ", array[i]);
//        	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	my_sort(arr, size);
//	return 0;
//}