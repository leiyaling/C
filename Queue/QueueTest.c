#include"Queue.h"

void QueueTest1()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	while (!QueueEmpty(&q1))
	{
		QDataType front = QueueFront(&q1);
		printf("%d ", front);
		QueuePop(&q1);

	}
	printf("\n");
	/*QueuePop(&q1, 1);
	QueuePop(&q1, 2);
	QueuePop(&q1, 3);
	QueuePop(&q1, 4);
	QueueDestroy(&q1);*/
}

void QueueTest2()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	printf("%d\n", QueueSize(&q1));
}
int main()
{
	//QueueTest1();
	QueueTest2();
	return 0;
}