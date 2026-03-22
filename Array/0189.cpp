#include <vector>

using namespace std;

// 辅助数组
void rotate(vector<int> &nums, int k)
{
    if (nums.size() <= 1 || k == 0)
        return;
    vector<int> copy(nums.size());
    k %= nums.size();
    for (int i = 0; i < nums.size(); ++i)
        copy[(i + k) % nums.size()] = nums[i];
    nums = copy;
}

// 原地置换
void rotate(vector<int> &nums, int k)
{
    if (nums.size() <= 1 || k == 0)
        return;
    for (; k > 0; --k)
    {
        int begin = nums.back();
        for (int i = nums.size() - 1; i > 0; --i)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = begin;
    }
}