int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ?leftDepth + 1 :rightDepth + 1;

}
//左右子树都是平衡二叉树
bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    else
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}