#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort(int* arr, int sz)
{

	for (int i = 0; i < sz - 1; i++)
	{

		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

}

void Print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test1()
{
	int arr[] = { 3,5,7,1,9,8,6,2,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	bubble_sort(arr, sz);
	Print(arr, sz);
}
//void qsort (void * base, //待排序数据的起始地址
//            size_t num,  //待排序数据的元素个数
//            size_t width,//待排序数据的元素大小（单位是字节）
//            int (*cmp) (const void*,const void*));//比较2个元素大小的函数指针


int cmp_int (const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//测试qsort函数的功能排序整形数据
void test2()
{
	int arr[] = { 3,5,7,1,9,8,6,2,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	Print(arr, sz);
}
//测试qsort函数的功能排序结构体数据
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name ,((struct Stu*)e2)->name);
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test3()
{
	struct Stu s[] = { {"zhangsan",14},{"lisi",16},{"wangwu",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
void test4()
{
	struct Stu s[] = { {"zhangsan",14},{"lisi",16},{"wangwu",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}


void Swap(char* buf1,char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;

	}
}
void bubble_sort_qsort(void* base, int sz,int width, int (*cmp) (const void*, const void*))
{

	for (int i = 0; i < sz - 1; i++)
	{

		for (int j = 0; j < sz - 1 - i; j++)
		{
			if(cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)
				//交换
				Swap((char*)base+j*width, (char*)base + (j+1) * width, width);
		}
	}

}
void test5()
{
	int arr[] = { 3,5,7,1,9,8,6,2,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	bubble_sort_qsort(arr,sz,sizeof(arr[0]),cmp_int);
	Print(arr, sz);
}

void test6()
{
	struct Stu s[] = { {"zhangsan",14},{"lisi",16},{"wangwu",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort_qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}