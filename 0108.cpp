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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBST(nums, 0, nums.size()); // 左闭右开区间
}

TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
{
    if (start == end)
        return nullptr;                  // 递归退出条件
    int mid = start + (end - start) / 2; // 防止溢出
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}