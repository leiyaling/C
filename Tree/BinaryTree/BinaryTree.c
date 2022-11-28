#include "BinaryTree.h"
#include "Queue.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	return newnode;

}
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* src, int n, int* pi)
{
	if (src[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[n];
	(*pi)++;

	cur->left = BinaryTreeCreateExe(src);
	cur->right = BinaryTreeCreateExe(src);

	return cur;
}

// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
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
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return 0;
	if (root->data == x)
		return root;

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet != NULL)
		return leftRet;

	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet != NULL)
		return rightRet;

	return NULL;

}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	BinaryTreePrevOrder(root->left);
	printf("%c", root->data);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	printf("%c", root->data);
	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;

	Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c", front->data);

		// ���Ӵ�������
		if(front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q,front->right);
	}
	printf("\n");
	QueueDestroy(&q);
}
bool BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode* cur;
	QueueInit(&qu);
	QueuePush(&qu, root);

	while (!QueueEmpty(&qu))
	{
		cur = QueueFront(&qu);
		QueuePop(&qu);
		//����������ˣ��ж϶������Ƿ��зǿյĽڵ㣬
		//��������ﶼ�ǿգ�������ȫ������
		if (!cur)
		{
			break;
		}
		else
		{
			QueuePush(&qu, cur->left);
			QueuePush(&qu, cur->right);
		}	
		
	}
	while (!QueueEmpty(&qu))
	{
		BTNode* front = QueueFront(&qu);
		QueuePop(&qu);
		if (!front)
		{
			QueueDestroy(&qu);
			return false;
		}
			
	}
	QueueDestroy(&qu);
	return true;
}