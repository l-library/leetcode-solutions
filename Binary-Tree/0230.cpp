struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count = 0;
int result = -1;
int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return -1;
    if (result != -1)
        return result;
    kthSmallest(root->left, k);
    count++;
    if (count == k)
    {
        result = root->val;
        return result;
    }
    kthSmallest(root->right, k);
    return result;
}