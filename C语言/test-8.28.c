#include<stdio.h>
#include<string.h>
#include<assert.h>
//void Print(int* arr, int size)
//{
//	/*while (arr != NULL)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}*/
//	int i = 0;
//	for (i; i < size; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, size);
//	return 0;
//}
//void reserve(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//	
//
//}
//int main()
//{
//	char str[256] = {0};
//	gets(str);
//	reserve(str);
//	printf("%s\n", str);
//	return 0;
//}
//void Print(int n)
//{
//	 //打印上半部分
//	int i = 0;
//	for (i; i < n; i++)
//	{
//		int j = 0;
//		for (j; j < n-i-1;j++)
//			{
//				printf(" ");
//		
//			}
//			for (j = 0; j <2*i+1; j++)
//				{
//					printf("*");
//				}
//			printf("\n");
//	}
//	//打印下半部分
//	for (i=0; i < n; i++)
//	{
//		int j = 0;
//		for (j; j < i + 1; j++)
//		{
//			printf(" ");
//
//		}
//		for (j = 0; j < 2*(n - i - 1)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("请输入行数：");
//	scanf_s("%d", &n);
//	Print(n);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i; i <= 100000; i++)
//	{
//		int count = 0;
//		while (i/10 != 0)
//		{
//			count++;
//		}
//		if((i%10)^count)
//	}
//	return 0;
//}
//int count_bit(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i; i < 32; i++)
//	{
//		if (1 == ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}
//n=11
//1011 ---n
//1010 ---n-1
//1010 ---n
//1001 ---n-1
//1000 ---n
//0111 ---n-1
//0000 ---n
//int count_bit(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int num = count_bit(n);
//	printf("%d\n",num);
//	return 0;
//}
//int main()
//{
//	int m, n = 0;
//	scanf_s("%d %d", &m, &n);
//	int i = 0;
//	int count = 0;
//	//for (i; i < 32; i++)
//	//{
//	//	//3  0011---0001  0001
//	//	//5  0101---0001  0001
//	//	//   001---001    001
//	//	//   010---001    000
//	//	if (((m >> i) & 1)!= ((n >> i) & 1))
//	//	{
//	//		count++;
//	//	}
//	//}
//	//异或  相同为0 相异为1
//	int ret = m ^ n;
//	while (ret)
//	{
//		ret = ret & (ret - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int i = 0;
//	//15  00000000000000000000000000001111
//	//    00000000000000000000000000000001
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf_s("%d", &n);
//    int arr[10][10] = { 0 };
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; i++)
//        {
//            scanf_s("%d", &arr[i][j]);
//        }
//    }
//    int flag = 1;
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j < i; i++)
//        {
//            if (arr[i][j] != 0)
//            {
//                flag = 0;
//                goto end;
//            }
//        }
//    }
//end:
//    if (flag == 1)
//        printf("YES\n");
//    else
//        printf("NO\n");
//    return 0;
//}
#include<stdio.h>
int walk(int n)
{
    if (n <= 2)
        return n;
    else if (n > 2)
        return walk(n - 1) + walk(n - 2);

}
int main()
{
    int n = 0;
    scanf_s("%d", &n);
    int ret = walk(n);
    printf("%d\n", ret);
    return 0;
}