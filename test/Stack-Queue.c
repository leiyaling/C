//用队列实现栈
typedef struct {
    Queue q1;
    Queue q2;

} MyStack;


MyStack* myStackCreate() {
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else{
        QueuePush(&obj->q2,x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }
    while(QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ,QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }
    int top=QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);
    return top;
}

int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->q1))
    {
       return QueueBack(&obj->q1);
    }
    else{
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) { 
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

