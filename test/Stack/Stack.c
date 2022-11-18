#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
//��ӡջ
void Print(Stack* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n ");
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newcapacity = ps->_capacity == 0 ? ps->_capacity = 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}
//����ջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
