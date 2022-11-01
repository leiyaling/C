#include <stdio.h>
#include <string.h>
#include <assert.h>
//str 主串
//sub 子串
//如果找到了，返回子串在主串中的下标，否则，返回-1
int BF(char* str, char* sub)
{
	assert(str && sub);
	if (str == NULL && sub == NULL)
		return -1;

	int lenStr = strlen(str);
	int lenSub = strlen(sub);

	int i = 0;//主串开始的下标
	int j = 0;//子串开始的下标
	while (i < lenStr && j < lenSub)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
			
		}
	}
	//如果子串走到空，代表找到了
	if (j >= lenSub)
	{
		return i - j;
	}
	//如果主串走到空，证明主串里没有子串
	return -1;
}
int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));//5
	printf("%d\n", BF("ababcabcdabcde", "abcde"));//9
	printf("%d\n", BF("ababcabcdabcde", "abcdef"));//-1
	return 0;
}
