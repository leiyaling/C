//对称二叉树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return true;

    if(!p || !q)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
}
bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
        return true;
    return isSameTree(root->left,root->right);
}