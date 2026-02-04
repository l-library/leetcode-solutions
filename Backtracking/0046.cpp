#include <vector>

using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &res, int left)
{
    if (left >= nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = left; i < nums.size(); ++i)
    {
        swap(nums[left], nums[i]);
        helper(nums, res, left + 1);
        swap(nums[left], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    helper(nums, res, 0);
    return res;
}