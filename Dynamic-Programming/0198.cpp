#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(dp[i - 1], (i - 2 >= 0 ? dp[i - 2] + nums[i] : max(dp[i - 1], nums[i])));
    }
    return max(dp[n - 1], dp[n - 2]);
}