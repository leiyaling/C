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
//    // 外层循环控制冒泡排序的趟数
//    // size-1表示：最后一趟区间中只剩余1个元素，该趟冒泡可以省略
//    for (i = 0; i < size - 1; ++i)
//    {
//        // 具体冒泡的方式：用相邻的两个元素进行比较，前一个大于后一个元素时，交换着两个数据，依次直到数组的末尾
//        for (int j = 1; j < size - i; ++j)
//        {
//            if (array[j - 1] > array[j])
//            {
//		flag=1;
//                int temp = array[j - 1];
//                array[j - 1] = array[j];
//                array[j] = temp;
//            }
//	if(flag==0)//第一次没有进入交换，代表数组是有序的，跳出循环
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