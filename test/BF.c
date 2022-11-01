#include <stdio.h>
#include <string.h>
#include <assert.h>
//str ����
//sub �Ӵ�
//����ҵ��ˣ������Ӵ��������е��±꣬���򣬷���-1
int BF(char* str, char* sub)
{
	assert(str && sub);
	if (str == NULL && sub == NULL)
		return -1;

	int lenStr = strlen(str);
	int lenSub = strlen(sub);

	int i = 0;//������ʼ���±�
	int j = 0;//�Ӵ���ʼ���±�
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
	//����Ӵ��ߵ��գ������ҵ���
	if (j >= lenSub)
	{
		return i - j;
	}
	//��������ߵ��գ�֤��������û���Ӵ�
	return -1;
}
int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));//5
	printf("%d\n", BF("ababcabcdabcde", "abcde"));//9
	printf("%d\n", BF("ababcabcdabcde", "abcdef"));//-1
	return 0;
}
