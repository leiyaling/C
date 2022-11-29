//另一颗树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return true;

    if(!p || !q)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(!root)
        return false;
    if(isSameTree(root,subRoot))
        return true;

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}