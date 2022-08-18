#include<stdio.h>
#include<stdlib.h>

typedef char BTreeDataType;
typedef struct BinaryTreeNode
{
	BTreeDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	PostOrder(root->right);
	PostOrder(root->left);
	printf("%c ", root->data);
}
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :TreeSize( root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL) 
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	
}
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E =(BTNode*) malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PreOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	printf("%d\n", TreeSize(A));
	printf("%d ", TreeLeafSize(A));
	return 0;
}