class Solution
{
public:
    void inorderTraverse(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        inorderTraverse(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraverse(root->right, inorder);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraverse(root, inorder);
        int s = 0;
        int e = inorder.size() - 1;
        while (s < e)
        {
            int sum = inorder[s] + inorder[e];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return false;
    }
};