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
//int main()
//{
//	//���ļ�
//
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	
//	// ���ļ�  һ��һ�ж�
//	char arr[20] = "########";
//	fgets(arr, 20, pf);
//	printf("%s", arr);
//
//
//	fgets(arr, 20, pf);
//	printf("%s", arr);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//дһ���ṹ�������
	struct people
	{
		char name[20];
		int age;
		float score;
	};
//int main()
//{
//	struct people s = { "����", 20, 88.8 };
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf,"%s %d %.1f",s.name,s.age,s.score);
//
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
	////��һ���ṹ�������
	//int main()
	//{
	//	struct people s = {0};
	//	//���ļ�
	//	FILE* pf = fopen("test.txt", "r");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}
	//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
	//	printf("%s %d %f\n", s.name, s.age, s.score);


	//	//�ر��ļ�
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}

	////������дһ���ṹ�������
	//int main()
	//{
	//	struct people s = { "����", 20, 88.8f };
	//	//���ļ�
	//	FILE* pf = fopen("test.txt", "wb");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}

	//	//������д�ļ�
	//	fwrite(&s, sizeof(s), 1, pf);


	//	//�ر��ļ�
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}
	//�����ƶ�һ���ṹ�������
	//int main()
	//{
	//	struct people s = { 0 };
	//	//���ļ�
	//	FILE* pf = fopen("test.txt", "rb");
	//	if (NULL == pf)
	//	{
	//		perror("fopen");
	//		return 1;
	//	}

	//	//������д�ļ�
	//	fread(&s, sizeof(s), 1, pf);
	//	printf("%s %d %f\n", s.name, s.age, s.score);

	//	//�ر��ļ�
	//	fclose(pf);
	//	pf = NULL;
	//	return 0;
	//}
	//int main()
	//{
	//	char buf[100] = { 0 };
	//	struct people tmp = { 0 };

	//	struct people s = { "����", 20, 88.8f };

	//	//������ṹ�������ת�����ַ���
	//	sprintf(buf, "%s %d %f", s.name, s.age, s.score);
	//	printf("%s\n", buf);


	//	//��buf�е��ַ�����ԭ�ɽṹ�������
	//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
	//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
	//	return 0;
	//}
	

//�ļ��������д
	int main()
	{
		struct people s = { 0 };
		//���ļ�
		FILE* pf = fopen("test.txt", "r");
		if (NULL == pf)
		{
			perror("fopen");
			return 1;
		}
		
		//���ļ�
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

		fseek(pf, 3, SEEK_SET);//��ͷ��ʼ��
		ch = fgetc(pf);//d
		printf("%c\n", ch);

		fseek(pf, -3, SEEK_END);//��β��ʼ��
		ch = fgetc(pf);
		printf("%c\n", ch);//e
	//�ر��ļ�
		fclose(pf);
		pf = NULL;
		return 0;
	}