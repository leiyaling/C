#include<stdio.h>
#include<assert.h>
//size_t my_strlen(const char* arr)//size_t����ֵ���޷��ŵ�
//{
//	assert(arr);
//	const char* start = arr;
//	const char* end = arr;
//	
//	while (*end !='\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int  main()
//{
//	char arr[] = "abcdef";
//	int len=my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while ( *dest++=*src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = { "abcdef"};
//	char arr2[30] = { 0 };
//	
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}
//char* my_strcat(char* dest, const char* src)
//{
//	//�ҵ�Ŀ��ռ��\0
//	char* cur=dest;
//	while (*cur != '\0')
//	{
//		cur++;
//	}
//	//�������ݵ�Դͷ\0֮��Ŀռ�
//	while (*cur++ = *src++)
//		{
//				;
//		}
//	return dest;
//}
//int main()
//{
//	char arr1[20] = { "hello " };
//	char arr2[] = { "world" };	
//	printf("%s\n", my_strcat(arr1, arr2));
//	return 0;
//
//}

//s1>s1����һ������0������
//s1 <s1����һ��С��0������
//s1=s1����0
//int my_strcmp(const char* s1, const char* s2)
//{
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//int main()
//{
//	char arr1[] = { "abcd" };
//	char arr2[] = { "abcde" };
//	int ret=my_strcmp(arr1,arr2);//�Ƚϵ��Ƕ�Ӧλ���ϵĴ�С�����ǳ���
//	if (ret > 0)
//		printf("arr1>arr2");
//	if (ret < 0)
//		printf("arr1<arr2");
//	else
//		printf("arr1=arr2");
//	return 0;
//}
char* my_strstr(const char*str1, const char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	if (str2 == '\0')
		return str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1!='\0' && *s2!='\0' && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char arr1[] = { "abbccd" };
	char arr2[] = { "bcd" };
	char* ret=my_strstr(arr1,arr2);
	if (ret == NULL)
		printf("������\n");
	else
		printf("%s\n",ret);
	return 0;
}