//重建二叉树
    //已知树的先序和中序遍历，希望重建二叉树

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
{
    if(pre.empty() || vin.empty())
        return NULL;
    vector<int> left_in, left_pre, right_in, right_pre;
    //先序遍历的第一个结点一定是树的根结点
    TreeNode* root = new TreeNode(pre[0]);
    int pos = 0;
    //在中序遍历中找到树的根结点
    for(; pos<vin.size(); ++pos)
    {
        if(vin[pos] == pre[0])
            break;
    }
    for(int i=0; i<vin.size(); ++i)
    {
        //处理左子树
        if(i < pos)
        {
            left_in.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }
        //处理右子树
        else if(i > pos)
        {
            right_in.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }
    }
    //递归重建
    root->left = reConstructBinaryTree(left_pre, left_in);
    root->right = reConstructBinaryTree(right_pre, right_in);
    return root;
}
