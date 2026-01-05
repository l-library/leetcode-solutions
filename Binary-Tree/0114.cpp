#include <queue>

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

TreeNode *helper(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }
    TreeNode *l_last = helper(root->left);
    TreeNode *r_last = helper(root->right);
    if (root->left)
    {
        auto right_root = root->right;
        root->right = root->left;
        root->left = nullptr;
        l_last->right = right_root;
    }
    if (r_last)
        return r_last;
    if (l_last)
        return l_last;
    else
        return root;
}

void flatten(TreeNode *root)
{
    helper(root);
}

int main()
{
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(2, a, nullptr);
    TreeNode *c = new TreeNode(1, b, nullptr);
    helper(c);
}