//二叉树的镜像-》数据结构中的面试题


void Mirror(TreeNode *pRoot) 
{
    if(pRoot == NULL)
        return;
    queue<TreeNode*> q;
    q.push(pRoot);
    while(!q.empty())
    {
        TreeNode* cur = q.front();
        TreeNode* tmp = cur->left;  
        cur->left = cur->right;
        cur->right = tmp;
        if(cur->left != NULL)
            q.push(cur->left)                   
        if(cur->right != NULL)
            q.push(cur->right);
        q.pop();
    }
}
