//栈实现队列
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
// 检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}
//返回栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}


typedef struct {
    Stack pushst;
    Stack popst;
} MyQueue;

bool myQueueEmpty(MyQueue* obj);
int myQueuePeek(MyQueue* obj);
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&queue->pushst);
    StackInit(&queue->popst);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    
        StackPush(&obj->pushst,x);
}

int myQueuePop(MyQueue* obj) {
  
    int peek = myQueuePeek(obj);
    StackPop(&obj->popst);
    return peek;
}

int myQueuePeek(MyQueue* obj) {
    if(StackEmpty(&obj->popst))
    {
        while(!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst,StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    return StackTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushst);
    StackDestroy(&obj->popst);
    free(obj);
}