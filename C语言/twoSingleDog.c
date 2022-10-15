#include<stdio.h>
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。

//1.将数据分成两组异或（异或满足交换律），分别找出每一组的单身狗
//2.分组：将数组中每一个元素异或，得到两个单身狗的异或值
//两个单身狗异或的二进制中一定有1，找到这个位置，数组中这个位置为1的为一组，为0的为一组
//3.分别异或
int main()
{
	int arr[20] = { 1,2,3,4,5,1,2,3,4,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	for (int i = 0; i < size; i++)
	{
		ret ^= arr[i];
	}
	//ret是5和9的异或值
	int pos;//5和9按位异或后二进制中第一个不同的位置
	for (int i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
		}
	}

	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >> pos == 1)
		{
			sum1 ^= arr[i];
		}
		else
		{
			sum2 ^= arr[i];
		}
	}
	printf("%d %d\n", sum1, sum2);
	return 0;
}