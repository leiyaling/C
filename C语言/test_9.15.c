#include<stdio.h>
//void find_num(int arr[3][3], int n, int col, int row)
//{
//	int i = 0;
//	int j = col - 1;
//	int flag = 0;
//	while( i<=row-1 && j >= 0)
//	{
//		if (n < arr[i][j])
//			{
//				j--;
//			}
//		else if (n > arr[i][j])
//			{
//				i++;
//			}
//		else 
//		{
//			flag = 1;
//			printf("找到了");
//			break;
//		}
//			
//	}
//	if (flag == 0)
//	{
//		printf("没找到");
//	}
//		
//}
//void find_num(int arr[3][3], int n, int *px, int *py)
//{
//	int i = 0;
//	int j = *py - 1;
//	int flag = 0;
//	while (i <= *px - 1 && j >= 0)
//	{
//		if (n < arr[i][j])
//		{
//			j--;
//		}
//		else if (n > arr[i][j])
//		{
//			i++;
//		}
//		else
//		{
//			//找到了
//			flag = 1;
//			*px = i;
//			*py = j;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		*px = -1;
//		*py = -1;
//	}
//
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//	int x = 3; 
//	int y = 3;
//	find_num(arr, n, &x, &y);
//	if (x == -1 && y == -1)
//		printf("找不到");
//	else
//		printf("找到了,下标是：%d %d",x,y);
//	return 0;
//}
#include<string.h>
//void left_move(char* arr, int k)
//{
//	int len = strlen(arr);
//	k %= len;
//	for (int j = 0; j < k; j++)
//	{
//		char tmp = arr[0];
//		for (int i = 0; i < len; i++)
//		{
//			
//			arr[i] = arr[i + 1];
//
//		}
//		arr[len - 1] = tmp;
//	}
//	
//}
//k的左边逆序	bacdef
//k的右边逆序	bafedc
//整体逆序		cdefab
#include<assert.h>
//void reverse(char* left,char*right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//	
//}
//void left_move(char* arr, int k)
//{
//	int len = strlen(arr);
//	k %= len;
//	reverse(arr, arr+k-1);
//	reverse(arr+k, arr+len-1);
//	reverse(arr, arr+len-1);
//
//}
//int main()
//{
//	char arr[] = { "abcdef" };
//	printf("%s\n", arr);
//	left_move(arr,2);
//	printf("%s\n", arr);
//	return 0;
//}
int is_left_move(char* arr1, char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	strncat(arr1, arr1, len1);// AABCDAABCD----BCDAA
	char* ret = strstr(arr1, arr2);
	if (ret == NULL)
		return 0;
	else
		return 1;
}
int main()
{
	char arr1[20] = "AABCD";
	char arr2[] = "BCDAA";
	int ret = is_left_move(arr1, arr2);
	if (1 == ret)
		printf("YES\n");
	if ( 0== ret)
		printf("NO\n");
	return 0;
}