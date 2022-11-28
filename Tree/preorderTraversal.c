int Treesize(struct TreeNode* root)
 {
     return root == NULL ? 0 :Treesize(root->left) + Treesize(root->right) + 1;
 }
void preorder(struct TreeNode* root,int* a,int* pi)
{
    if(root == NULL)
      return ;
    a[(*pi)++] = root->val;
    preorder(root->left,a,pi);
    preorder(root->right,a,pi);

}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    * returnSize = Treesize(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    int i = 0;
    preorder(root,a,&i);
    return a;
}