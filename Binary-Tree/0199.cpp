#include <vector>
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

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};
    // 先遍历
    queue<TreeNode *> every;
    every.push(root);
    vector<int> res;
    while (!every.empty())
    {
        int n = every.size();
        int temp = 101; // 范围在-100到100 或者可以设置一个是否被修改的flag
        for (int i = 0; i < n; ++i)
        {
            auto current = every.front();
            if (!current)
            {
                every.pop();
                continue;
            }
            every.push(current->left);
            every.push(current->right);
            temp = current->val;
            every.pop();
        }
        if (temp != 101)
            res.push_back(temp);
    }
    return res;
}