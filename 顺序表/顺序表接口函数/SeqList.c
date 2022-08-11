#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqDatatype* tmp = (SeqDatatype*)realloc(ps->a, newcapacity * sizeof(SeqDatatype));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SL* ps, SeqDatatype* x)
{
	/*SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);

}
void SeqListPopBack(SL* ps)
{
	/*assert(ps->size>0);
	ps->size--;*/
	SeqListErase(ps, ps->size-1);

}
void SeqListPushFront(SL* ps, SeqDatatype* x)
{
	/*SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end>=0)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopFront(SL* ps)
{
	/*assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;

	}
	ps->size--;*/
	SeqListErase(ps, 0);
}
int SeqListFind(SL* ps, SeqDatatype* x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
		
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SeqDatatype* x)
{
	assert(pos >=0 && pos<=ps->size );
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
			--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos+1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;

	}
	ps->size--;
}