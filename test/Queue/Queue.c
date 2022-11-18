#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}
//��ӡ����
void QueuePrint(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_front == NULL)
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{	
	assert(q);
	QNode* cur = q->_front;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
// �������Ƿ�Ϊ�� 
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front==NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		QNode*  next = cur->_next;
		free(q->_front);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}