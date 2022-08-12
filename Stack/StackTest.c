#include"Stack.h"

void Test1()
{
	ST s1;
	StackInit(&s1);
	StackPush(&s1, 1);
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	StackPush(&s1, 4);
	StackPop(&s1, 1);
	StackPop(&s1, 2);
	StackPop(&s1, 3);
	StackPop(&s1, 4);

	StackDestroy(&s1);
}
void Test2()
{
	ST s1;
	StackInit(&s1);
	StackPush(&s1, 1);
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	StackPush(&s1, 4);
	
	printf("%d ", StackTop(&s1));
	StackPop(&s1);
	printf("%d ", StackTop(&s1));
	StackPop(&s1);
	
	StackPush(&s1, 5);
	StackPush(&s1, 6);
	while (!StackEmpty(&s1))
	{
		printf("%d ", StackTop(&s1));
		StackPop(&s1);
	}

	StackDestroy(&s1);
}
int main()
{
	//Test1();
	Test2();
	return 0;
}