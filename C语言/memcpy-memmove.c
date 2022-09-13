#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest,const void* src,size_t num)//num的单位是字节
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)//从前向后拷贝
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else//从后向前拷贝
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 ,10};
	int arr2[20] = { 0 };
	//my_memcpy(arr2,arr1,8);
	my_memmove(arr1+2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	
	return 0;
}