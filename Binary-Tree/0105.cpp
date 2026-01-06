#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &ppre, int lpin, int rpin)
{
    if (ppre >= preorder.size() || lpin > rpin)
        return nullptr;
    int root_val = preorder[ppre];
    // 查找头节点在中序遍历中的位置
    int i = lpin;
    for (; i <= rpin; ++i)
    {
        if (inorder[i] == root_val)
            break;
    }
    TreeNode *root = new TreeNode(root_val);
    // 指针向后移动
    ppre += 1;
    // 递归建立树
    root->left = helper(preorder, inorder, ppre, lpin, i - 1);
    root->right = helper(preorder, inorder, ppre, i + 1, rpin);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int ppre = 0;
    return helper(preorder, inorder, ppre, 0, inorder.size() - 1);
}