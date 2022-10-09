#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	//打开文件
//	//相对路径
//	FILE* pf = fopen("test.txt","w");
//
//	//绝对路径
//	//FILE* pf = fopen("D:\\test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//写文件
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	//打开文件
//	//相对路径
//	FILE* pf = fopen("test.txt", "r");
//
//	
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//读文件
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
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//按照顺序写文本行
//int main()
//{
//	//打开文件
//	
//	FILE* pf = fopen("test.txt","w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//写文件  一行一行写
//	fputs("hello\n",pf);
//	fputs("world\n", pf);

//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//按照顺序读取文本行
int main()
{
	//打开文件

	FILE* pf = fopen("test.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return 1;
	}

	
	// 读文件  一行一行读
	char arr[20] = "########";
	fgets(arr, 20, pf);
	printf("%s", arr);


	fgets(arr, 20, pf);
	printf("%s", arr);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}