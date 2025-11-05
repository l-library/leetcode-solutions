#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  // 递归解法
  vector<int> inorderTraversal_1(TreeNode* root) {
    // 退出条件
    if (root == nullptr) return {};
    vector<int> result;
    vector<int> left = inorderTraversal_1(root->left);
    vector<int> right = inorderTraversal_1(root->right);
    // 递归遍历
    result.insert(result.end(), left.begin(),
                  left.end());  // 按中序遍历的顺序（左子女，根，右子女）
    result.push_back(root->val);
    result.insert(result.end(), right.begin(), right.end());
    return result;
  }
  // 非递归遍历（利用栈）
  vector<int> inorderTraversal(TreeNode* root) {
    // 退出条件
    if (root == nullptr) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    while (current != nullptr || !stk.empty()) {
      if (current != nullptr) {
        stk.push(current);
        current = current->left;
      } else {                // current==nullptr && !stk.empty()
        current = stk.top();  // 回到上一个节点
        stk.pop();
        result.push_back(current->val);  // 中序遍历
        current = current->right;
      }
    }
    return result;
  }
};