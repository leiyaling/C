#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void GetNext(int* next, const char* sub)
{
	int lensub = strlen(sub);
	next[0] = -1;
	next[1] = 0;
	int i = 2;//下一项
	int k = 0;//前一项的K
	while (i < lensub)//next数组还没有遍历完
	{
		if ((k == -1) || sub[k] == sub[i - 1])//
		{
			next[i] = k + 1;
			i++;
			k++;//k = k+1下一个K的值新的K值
		}
		else
		{
			k = next[k];
		}
	}
}
int KMP(const char* s, const char* sub, int pos)
{
	int i = pos;
	int j = 0;
	int lens = strlen(s);
	int lensub = strlen(sub);
	int* next = (int*)malloc(lensub * sizeof(int));//和子串一样长
	assert(next != NULL);
	GetNext(next, sub);
	while (i < lens && j < lensub)
	{
		if ((j == -1) || (s[i] == sub[j]))
		{
			i++;
			j++;
		}
		else
		{
			j = next [j];
		}
	}
	free(next);
	if (j >= lensub)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char* str = "ababcabcdabcde";
	char* sub = "abcd";
	printf("%d\n", KMP(str, sub, 0));
	return 0;
}