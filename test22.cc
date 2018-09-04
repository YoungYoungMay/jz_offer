//树的子结构
    //输入两棵树A，B，判断B树是不是A树的子结构
    //约定空树不是任意一个树的子结构

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot1==NULL||pRoot2==NULL)
        return false;
    //当前根结点表示的整个树、左子树、右子树，依次与B树比较
     if(pRoot1->val == pRoot2->val)
     {
         if(dfs(pRoot1,pRoot2))
            return true;
     }
     return HasSubtree(pRoot1->left,pRoot2)|| HasSubtree(pRoot1->right,pRoot2);            
}

bool dfs(TreeNode* r1, TreeNode* r2)//判断传入的子树是否完全相同
{
    //判断r1和r2是否为空的顺序不能改变
    if(r2 == NULL)//若此时r2为空，说明已经比较完了
        return true;
    if(r1 == NULL)//r2不为空但是r1为空了，说明不是子树
        return false;
    if(r1->val != r2->val)
        return false;
    return dfs(r1->left, r2->left)&&dfs(r1->right, r2->right);
}
