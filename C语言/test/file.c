#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	//���ļ�
//	//���·��
//	FILE* pf = fopen("test.txt","w");
//
//	//����·��
//	//FILE* pf = fopen("D:\\test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//д�ļ�
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	//���ļ�
//	//���·��
//	FILE* pf = fopen("test.txt", "r");
//
//	
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//���ļ�
//	/*int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		int ch=fgetc(pf);
//		printf("%c ", ch);
//	}*/
//	int ch = 0;
//	while ((ch = fgetc(pf) != EOF))
//	{
//		printf("%c ", ch);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//����˳��д�ı���
//int main()
//{
//	//���ļ�
//	
//	FILE* pf = fopen("test.txt","w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//д�ļ�  һ��һ��д
//	fputs("hello\n",pf);
//	fputs("world\n", pf);

//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//����˳���ȡ�ı���
int main()
{
	//���ļ�

	FILE* pf = fopen("test.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return 1;
	}

	
	// ���ļ�  һ��һ�ж�
	char arr[20] = "########";
	fgets(arr, 20, pf);
	printf("%s", arr);


	fgets(arr, 20, pf);
	printf("%s", arr);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}