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
//int main()
//{
//	//打开文件
//
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	
//	// 读文件  一行一行读
//	char arr[20] = "########";
//	fgets(arr, 20, pf);
//	printf("%s", arr);
//
//
//	fgets(arr, 20, pf);
//	printf("%s", arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//写一个结构体的数据
	struct people
	{
		char name[20];
		int age;
		float score;
	};
//int main()
//{
//	struct people s = { "张三", 20, 88.8 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf,"%s %d %.1f",s.name,s.age,s.score);
//
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
	////读一个结构体的数据
	//int main()
	//{
	//	struct people s = {0};
	//	//打开文件
	//	FILE* pf = fopen("test.txt", "r");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}
	//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
	//	printf("%s %d %f\n", s.name, s.age, s.score);


	//	//关闭文件
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}

	////二进制写一个结构体的数据
	//int main()
	//{
	//	struct people s = { "张三", 20, 88.8f };
	//	//打开文件
	//	FILE* pf = fopen("test.txt", "wb");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}

	//	//二进制写文件
	//	fwrite(&s, sizeof(s), 1, pf);


	//	//关闭文件
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}
	//二进制读一个结构体的数据
	//int main()
	//{
	//	struct people s = { 0 };
	//	//打开文件
	//	FILE* pf = fopen("test.txt", "rb");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}

	//	//二进制写文件
	//	fread(&s, sizeof(s), 1, pf);
	//	printf("%s %d %f\n", s.name, s.age, s.score);

	//	//关闭文件
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}
	//int main()
	//{
	//	char buf[100] = { 0 };
	//	struct people tmp = { 0 };

	//	struct people s = { "张三", 20, 88.8f };

	//	//把这个结构体的数据转换成字符串
	//	sprintf(buf, "%s %d %f", s.name, s.age, s.score);
	//	printf("%s\n", buf);


	//	//把buf中的字符串还原成结构体的数据
	//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
	//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
	//	return 0;
	//}
	

//文件的随机读写
	int main()
	{
		struct people s = { 0 };
		//打开文件
		FILE* pf = fopen("test.txt", "r");
		if (NULL == pf)
		{
			perror("fopen");
			return 1;
		}
		
		//读文件
		//int ch = fgetc(pf);
		//printf("%c\n", ch);//a
		//fseek(pf, 2, SEEK_CUR);

		//ch = fgetc(pf);
		//printf("%c\n", ch);//d
		//

		//int pos = ftell(pf);
		//printf("%c\n", pos);//a
		//rewind(pf);


		int ch = fgetc(pf);
		printf("%c\n", ch);//a

		ch = fgetc(pf);
		printf("%c\n", ch);//b

		fseek(pf, 3, SEEK_SET);//从头开始读
		ch = fgetc(pf);//d
		printf("%c\n", ch);

		fseek(pf, -3, SEEK_END);//从尾开始读
		ch = fgetc(pf);
		printf("%c\n", ch);//e
	//关闭文件
		fclose(pf);
		pf = NULL;
		return 0;
	}