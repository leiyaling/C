#include<stdio.h>
#include<string.h>
int Binary_Search(int *a,int k,int size)
{
	int left = 0;
	int right = size - 1;
	
	while (left <= right)
	{
		int mid = (left+right)/2;
		if (k<a[mid] ) {
			right = mid-1;
		}
		else if(k> a[mid])
		{
			left = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int k =8;
	int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a) / sizeof(a[0]);
	int ret= Binary_Search(a,k,size);
	if (ret == -1)
		printf("找不到");
	else 
		printf("找到了,下标为：%d",ret);
}
