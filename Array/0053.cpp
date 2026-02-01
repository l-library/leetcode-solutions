#include <vector>

using namespace std;

// 超时
int maxSubArray_1(vector<int> &nums)
{
    int res = 0;
    vector<int> scores(nums.size(), 0);
    scores[0] = nums[0];
    res = scores[0];
    // 第一次遍历
    for (int right = 1; right < nums.size(); ++right)
    {
        scores[right] = scores[right - 1] + nums[right];
        if (scores[right] > res)
            res = scores[right];
    }
    // 第二次
    for (int left = 1; left < nums.size(); ++left)
    {
        for (int i = 0; i < scores.size(); ++i)
        {
            if (left > i)
            {
                scores[i] = 0;
                continue;
            }
            else
                scores[i] -= nums[left - 1];
            if (scores[i] > res)
                res = scores[i];
        }
    }
    return res;
}
// 动态规划
int maxSubArray(vector<int> &nums)
{
    int pre = 0, res = nums[0];
    for (auto &num : nums)
    {
        pre = max(pre + num, num);
        res = max(pre, res);
    }
    return res;
}