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
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
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
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	BinaryTreePrevOrder(root->left);
	printf("%c", root->data);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	printf("%c", root->data);
	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c", root->data);
}
// 层序遍历
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

		// 孩子带进队列
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
		//如果遇到空了，判断队列里是否有非空的节点，
		//如果队列里都是空，则是完全二叉树
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