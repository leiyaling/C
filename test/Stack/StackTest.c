#include "Stack.h"
int main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 4);
	Print(&st);
	/*StackPop(&st);
	StackPop(&st);
	Print(&st);*/
	STDataType data = StackTop(&st);
	printf("%d\n", data);
	printf("%d",StackSize(&st));
	return 0;
}