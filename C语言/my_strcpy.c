#include<stdio.h>
#include<assert.h>
#include<string.h>
//void my_strcpy(char* dest,const char* src)
//{
//	assert(NULL != dest);
//	assert(NULL != src);
//	while (*src!='\0')
//	{
//		*dest++ = *src++;//hello worldµÄ¿½±´
//	
//	}
//	*dest = *src;//\0 µÄ¿½±´
//
//}
void my_strcpy(char* dest, const char* src)
{
	assert(NULL != dest);
	assert(NULL != src);
	while (*dest++ = *src++)
	{
		;
	}
}
int main()
{
	char arr2[20] = "*****************";
	char arr1[] = "hello world";
	my_strcpy(arr2,arr1);
	printf(" %s\n ", arr2);
	return 0;
}