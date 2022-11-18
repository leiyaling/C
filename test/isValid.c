#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef char STDataType;
typedef struct Stack
{
    STDataType* _a;
    int _top;		// ջ��
    int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
    assert(ps);
    ps->_a = NULL;
    ps->_capacity = 0;
    ps->_top = 0;
}
// ���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
    assert(ps);
    return ps->_top == 0;
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
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
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

bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    //��������ջ�������ų�ջ��Ԫ�ؽ���ƥ��
    while (*s)
    {
        if (*s == '{' || *s == '[' || *s == '(')
        {
            StackPush(&st, *s);
            s++;
        }
        else
        {
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            //��ƥ��
            if ((*s == '}' && top != '{')
                || (*s == ']' && top != '[')
                || (*s == ')' && top != '('))
            {
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }
    //ջΪ�մ�������ȫ��ƥ����
    bool ret = StackEmpty(&st);
    StackDestroy(&st);

    return ret;
}
int main()
{
    char s[10] = {'(',')'};
    printf("%d ", isValid(s));
    return 0;
}