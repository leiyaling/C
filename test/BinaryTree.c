#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char QDataType;
//��ʽ�ṹ����ʾ����
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
//���еĽṹ
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->head = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}


}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}

}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}



typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryNode* left;
	struct BinaryNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	node->data = x;
	node->left = node->right = NULL;
	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');
	BTNode* nodeG = BuyNode('G');


	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	nodeF->right = nodeG;

	return nodeA;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}
		
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);

}
// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);

}
// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);

}

// �������������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		// ���Ӵ�������
		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");

	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}

	// ���������Ժ󣬼�������ʣ�µĽڵ�
	// 1��ʣ��ȫ�ǿո���������ȫ������
	// 2��ʣ�´��ڷǿգ�������ȫ������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}
// �������ڵ����
// ��������˼�룺��ε��ô�������
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;

}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//root�����ڿգ�kҲ������1��˵��root������ĵ�k�ڵ�����������
	//ת���������������ĵ�k-1��Ľڵ�����
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return 0;
	if (root->data = x)
		return root;
	BTNode* leftRet = BinaryTreeFind(root->left,x);
	if (leftRet != NULL)
		return leftRet;
	BTNode* rightRet = BinaryTreeFind(root->right,x);
	if (rightRet != NULL)
		return rightRet;
	return NULL;
}
// ���������/�߶�
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	/*PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root,3));
	printf("%d\n", BinaryTreeDepth(root));*/
	BinaryTreeLevelOrder(root);
	//BinaryTreeComplete(root);
	BinaryTreeDestory(root);
	root = NULL;
	return 0;
}