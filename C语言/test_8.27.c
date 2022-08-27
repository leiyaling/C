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

//int  Test(unsigned int x)
//{
//	
//	if (x == 0)
//		return 1;
//	/*for ( i = 1; i <= x; i++)
//	{
//
//		ret = ret * i;
//	}*/
//
//	return Test(x-1)* x;
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个数字：");
//	scanf_s("%d", &n);
//	int r=Test(n);
//	printf("%d\n", r);
//}
//int Test(int x,int y)
//{
//	if (y == 0)
//		return 1;
//	return Test(x,y-1)*x;
//}
//int DigitSum(int x)//1729
//{
//	if (x < 10)
//		return x;
//	return x % 10 + DigitSum(x /10);
//
//}
/*void reverse_string(char* string)
{

}
int main()
{
	char arr[] = "abcdef";
	scanf_s("%d", &arr);
	int ret= DigitSum(n);
	printf("%d",ret);
}*/
//1 1 2 3 5 8 13 21 34 55
/*int Fib(int n)
{
	if (n <=2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int ret=Fib(n);
	printf("%d", ret);
	return 0;
}
int main()
{
	char A[5] = "hello";
	char B[5] = "wrold";
	int i = 0;
	int tmp = 0;
	for (i = 0;i < 5; i++)
	{
		tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%c", A[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%c", B[i]);
	}
	return 0;
}
void Init(int* arr,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void Print(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	int tmp = 0;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}*/
//void Swap(int x,int y)
//{
//	//x = x + y;//x=3 y=2
//	//y = x - y;//y=1 x=3
//	//x = x - y;//x=2 y=1
//	//按位异或
//	//1-  00000000000000000000000000000001
//	//2-  00000000000000000000000000000010
//	x=x^ y;//00000000000000000000000000000011  x=3
//	y = x ^ y;//x^y^y --y=1
//	x = x ^ y;//x^y 
//	//00000000000000000000000000000001
//	//00000000000000000000000000000011 x=00000000000000000000000000000010
//	printf("%d %d", x, y);
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	return 0;
//}
//int Test(int x)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 16; i++)
//	{
//		if ((x & 1) == 1)
//		{
//			count++;
//			x = x >>1 ;
//		}
//		else
//		{
//			x = x >> 1;
//		}
//			
//	}
//	return count;
//}
//int main()
//{
//	int a = 15;//00000000000000000000000000001111
//	int ret=Test(a);
//	printf("%d\n", ret);
//	return 0;
//}
int main()
{
	int count = 0;
	int a = 1999;
	int b = 2299;
	a=a^ b;
	for (int i = 0; i < 16; i++)
	{
		if ((a & 1) == 1)
		{
			count++;
						
		}
					
		a= a >>1 ;
					
	}
	printf("%d\n", count);
	return 0;
}