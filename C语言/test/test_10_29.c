#include <stdio.h>
//struct S
//{
//	int a;
//	int b;
//	int c;
//	int d;
//};
////位段-其中的位其实是二进制位
//struct A
//{
//	//4byte - 32bit
//	int _a : 2;//30
//	int _b : 5;//25
//	int _c : 10;//15
//	int _d : 30;//剩下15个字节不够用，又开辟了四个字节，但是位段不确定是否还会使用这15个字节
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

//枚举类型

//enum Color
//{
//	//枚举的可能取值
//	//每一个可能的取值是常量
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
//		printf("小端\n");
//	else
//		printf("大端\n");
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
