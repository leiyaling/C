#include <stdio.h>
#include <stdlib.h>
//构建二叉树
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
 struct TreeNode* rebuildTree(char* str,int* pi)
{
    if(str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    struct TreeNode* root = ( struct TreeNode*)malloc(sizeof( struct TreeNode));
    root->val = str[(*pi)++];
    root->left = rebuildTree(str,pi);
    root->right =  rebuildTree(str,pi);
    return root;
}
void InOrder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    InOrder(root->left);
    printf("%c ",root->val);
    InOrder(root->right);
}
int main() {
    char str[100];
    scanf("%s",str);
    int i;
    struct TreeNode* root = rebuildTree(str, &i);
    InOrder(root);
    return 0;
}