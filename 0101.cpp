#include <queue>
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

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    queue<TreeNode *> single_line; // 广度优先遍历
    single_line.push(root);
    int every_length = 1;
    vector<int> arr;
    while (!single_line.empty())
    {
        int num = single_line.back()->val;
        // 判断是否对称
        if (arr.size() < every_length)
            arr.push_back(single_line.front()->val);
        else
        {
            while (!arr.empty())
            {
                if (num == arr.back())
                    arr.pop_back();
                else
                    return false;
            }
        }
        single_line.push(single_line.front()->left);
        single_line.push(single_line.front()->right);
        single_line.pop();
    }
    if (!arr.empty())
        return false;
}