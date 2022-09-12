#include<stdio.h>
#include<assert.h>
size_t my_strlen(const char* arr)//size_t返回值四无符号的
{
	assert(arr);
	const char* start = arr;
	const char* end = arr;
	
	while (*end !='\0')
	{
		end++;
	}
	return end - start;
}
int  main()
{
	char arr[] = "abcdef";
	int len=my_strlen(arr);
	printf("%d", len);
	return 0;
}