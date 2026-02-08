#include <vector>

using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &res, int left)
{
    if (left >= nums.size())
    {
        res.push_back({});
        return;
    }
    helper(nums, res, left + 1);
    int size = res.size();
    for (int i = 0; i < size; ++i)
    {
        auto copy = res.at(i);
        copy.push_back(nums.at(left));
        res.push_back(copy);
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    helper(nums, res, 0);
    return res;
}