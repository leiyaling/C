#include "Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,0);
	QueuePush(&q,6);
	QueuePush(&q,3);
	QueuePrint(&q);
	QueuePop(&q, 6);
	QueuePop(&q, 3);
	QueuePrint(&q);
	printf("%d ",QueueBack(&q));
	printf("%d ",QueueFront(&q));
	printf("%d ",QueueSize(&q));
	return 0;
}