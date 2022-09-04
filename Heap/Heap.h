#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>

typedef int DataHeaptype;

typedef struct Heap
{
	DataHeaptype* a;
	int size;
	int capacity;
}HP;
void HeapInit(HP* hp);
void HeapDistroy(HP* hp);
void HeapPrint(HP* hp);
void HeapPush(HP* hp, DataHeaptype x);
void HeapPop(HP* hp);
bool HeapEmpty(HP* hp);
int HeapSize(HP* hp);
void Swap(DataHeaptype* px, DataHeaptype* py);
DataHeaptype HeapTop(HP* hp);
void AdjustUp(int* a, int child);
void AdjustDown(int* a, int n, int parent);
