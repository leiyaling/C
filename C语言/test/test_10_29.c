#include <stdio.h>
//struct S
//{
//	int a;
//	int b;
//	int c;
//	int d;
//};
////λ��-���е�λ��ʵ�Ƕ�����λ
//struct A
//{
//	//4byte - 32bit
//	int _a : 2;//30
//	int _b : 5;//25
//	int _c : 10;//15
//	int _d : 30;//ʣ��15���ֽڲ����ã��ֿ������ĸ��ֽڣ�����λ�β�ȷ���Ƿ񻹻�ʹ����15���ֽ�
//	//4byte- 32bit
//};
////47bit
////1byte - 8bit
////6byte
//int main()
//{
//	printf("%d\n", sizeof(struct S));//16
//	printf("%d\n", sizeof(struct A));//8
//
//	return 0;
//}

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//}

//ö������

//enum Color
//{
//	//ö�ٵĿ���ȡֵ
//	//ÿһ�����ܵ�ȡֵ�ǳ���
//	RED = 5,
//	GREEN = 7,
//	BLUE = 10
//};
//int main()
//{
//	
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	return 0;
//}
//
//union Un
//{
//	char c;//1
//	int i;//4
//	double d;//8
//};
//
//int main()
//{
//	union Un un;
//	printf("%p\n", &un);
//	printf("%p\n", &(un.c));
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.d));
//	return 0;
//}

//int check_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("С��\n");
//	else
//		printf("���\n");
//	return 0;
//}

union Un
{
	char arr[5];//5 1 8 1
	int i;//4 4
};
int main()
{
	printf("%d\n", sizeof(union Un));

	return 0;
}
