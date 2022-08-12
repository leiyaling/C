#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int SLDatatype;
typedef struct Stack
{
	SLDatatype* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps,SLDatatype x);
void StackPop(ST* ps);
SLDatatype StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
