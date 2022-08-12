#include"Stack.h"


void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top =ps->capacity = 0;
}
void StackPush(ST* ps, SLDatatype x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, sizeof(SLDatatype) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}	
		ps->a[ps->top] = x;
		ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));

	ps->top--;
}
SLDatatype StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top==0;
}