#include <iostream>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    queue<TreeNode *> que;
    que.push(root);
    vector<vector<int>> result;
    while (!que.empty())
    { // 遍历所有层
        int current_amount = que.size();
        vector<int> current_layer;
        for (int i = 0; i < current_amount; ++i)
        { // 遍历当前层的所有元素
            if (que.front()->left != nullptr)
                que.push(que.front()->left);
            if (que.front()->right != nullptr)
                que.push(que.front()->right);
            current_layer.push_back(que.front()->val);
            que.pop();
        }
        result.push_back(current_layer);
    }
    return result;
}