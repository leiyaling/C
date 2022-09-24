#include<stdio.h>
#include<assert.h>
//char* strncpy(char* dest, const char* src, size_t n)

//char* my_strncpy(char* dest, const char* src, size_t n)
//{
//	assert(dest && src);
//	while (n--&&*src!='\0')
//	{
//		*dest++ = *src++;
//		
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[20]="**********";
//	my_strncpy(arr2, arr1, 8);
//	printf("%s\n", arr2);
//	return 0;
//}
char*  my_strncat(char* dest, const char* src, size_t n)
{
	assert(dest && src);
	char* tmp = dest;
	while (*dest!='\0')
	{
		dest++;
	}
	while (n-- && *src!='\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return tmp;
}
int main()
{
	char arr1[] = "world hhhh";
	char arr2[20] = "hello ";
	my_strncat(arr2, arr1, 5);
	printf("%s\n", arr2);
	return 0;
}



//int atoi(const char* str)
//int my_atoi(char* arr)
//{
//
//}
//int main()
//{
//	char arr[] = "1234";
//	int val = my_atoi(arr);
//	return 0;
//}