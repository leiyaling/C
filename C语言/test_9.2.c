#include<stdio.h>
//int main()
//{
//	//int a=20;
//	//4byte = 32bit
//	//00000000000000000000000000010100 ---原码
//	//00000000000000000000000000010100 ---反码
//	//00000000000000000000000000010100 ---补码
//
//	int b = -10;
//	//10000000000000000000000000001010 ---原码
//	//11111111111111111111111111110101---反码
//	//11111111111111111111111111110111 ---补码
//	//fffffff6  ---十六进制
//
//
//	int c = 1 - 1;
//	//1+(-1) 
//	// 原码的计算是错误的
//	//00000000000000000000000000000001
//	//10000000000000000000000000000001
//	//10000000000000000000000000000010 -->-2
//	
//	//补码计算
//	//00000000000000000000000000000001 ---1的补码
//	//11111111111111111111111111111111 ---(-1)的补码
//	//100000000000000000000000000000000  int类型只存32个比特位，结果---00000000000000000000000000000000
//	//
//
//
//
//
//
//
//
//
//
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//
//	if (*p == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
// 
// 
// 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//
//B选手说：我第二，E第四；
//
//C选手说：我第一，D第二；
//
//D选手说：C最后，我第三；
//
//E选手说：我第四，A第一；
//
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//int main()
//{
//	int a, b, c, d, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if ((a* b* c* d* e == 120) && (a + b + c + d + e == 15))
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main()
{
	int killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer!='A') + (killer=='C') + (killer=='D') + (killer!='D') == 3)
		{
			printf("%c\n", killer);
		}
	}

	return 0;
}