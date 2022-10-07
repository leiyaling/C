//数组实现循环队列
typedef struct {
    int *a;
    int front;
    int tail;
    int k;

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->a = (int*)malloc(sizeof(int)*(k+1));
    cq->front = cq->tail = 0;
    cq->k = k;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    obj->a[obj->tail]=value;
    ++obj->tail;
    obj->tail %= (obj->k+1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    ++obj->front;
    obj->front %= (obj->k+1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;

    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;

    int i=(obj->tail+obj->k) % (obj->k+1);
    return obj->a[i];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front ==obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail+1) % (obj->k+1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}