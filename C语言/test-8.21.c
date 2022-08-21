#include<stdio.h>
#include<math.h>
/*int main()
{
	int count = 0;
	int i = 0;
	for (i = 1; i <= 100; i++)

	{
		if (i % 10 == 9)
		{
			count++;
			printf("%d\n", i);
		}
		 if (i / 10 == 9)
		{
			count++;
			printf("%d\n", i);
		}

	}
	printf("count=%d\n", count);*/
	/*int i =0;
	double sum =0.0;
	double ret = 1.0;
	for (i = 1; i <= 100; i++)
	{
		ret= (pow(-1, i + 1)) / i;
		sum += ret;
	}
	printf("%lf\n", sum);

	
	
	return 0;
}*/
//void Mul(int input)
//{
//	int i = 0;
//	for (i = 1; i <= input; i++)
//		{
//			int j = 0;
//			for (j = 1;j<=i; j++)
//			{
//				printf("%d*%d=%d ", i, j, i * j);
//			}
//			printf("\n");
//		}
//}
//void Swap(int*x,int*y)
//{
//	int tmp = 0;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//
//}
//int Is_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0)||x%400==0)
//		return 1;
//	else
//		return -1;
//}
/*int Is_number(int x)
{
	int i = 0;
	for (i = 2; i < x; i++)
	{
		if (x % i == 0)
			return 1;
 }
	return -1;
}
int main()
{
	int i = 0;
	for (i = 101; i < 200; i++)
	{
		int ret=Is_number(i);
		if (ret == -1)
			printf("%d\n", i);

	}int number = 0;
	printf("请输入一个整数：");
	scanf_s("%d", &number);
	int ret=Is_number(number);
	if (ret == 1)
		printf("%d\n",number);
	else
		printf("NO\n");*/
	/*int input = 0;
	printf("请输入一个数：");
	scanf_s("%d", &input);
    Mul(input);*/
	/*int a = 0;
	int b = 0;
	printf("请输入两个整数：");
	scanf_s("%d %d", &a,&b);
	Swap(&a, &b);
	printf("%d %d", a, b);*/
	/*int year = 0;
	printf("请输入年份：");
	scanf_s("%d",&year);
	int ret = Is_year(year);
	if (ret == 1)
		printf("YES\n");
	else
		printf("NO\n");
}
void Divide(unsigned int number)
{
	if(number<10)
	{
		printf("%d ", number);
	}
	else{
		printf("%d ", number % 10);
		Divide(number/ 10);
	}
}
void print(unsigned int n)
 {
	if(n>9)
		print(n/10);
	printf("%d ", n%10);
 }

 */

int  Test(unsigned int x)
{
	
	if (x == 0)
		return 1;
	/*for ( i = 1; i <= x; i++)
	{

		ret = ret * i;
	}*/

	return Test(x-1)* x;
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf_s("%d", &n);
	int r=Test(n);
	printf("%d\n", r);
}