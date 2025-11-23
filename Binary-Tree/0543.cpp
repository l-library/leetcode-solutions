#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

int result = 0;
int getMaxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int left = getMaxDepth(root->left);
    int right = getMaxDepth(root->right);
    result = max(left + right, result);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    getMaxDepth(root);
    return result;
}

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3, &a, &b);
    diameterOfBinaryTree(&c);
}