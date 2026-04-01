#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        int minn = INT_MAX;
        for (auto coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != -1)
                minn = min(minn, dp[i - coin]);
        }
        if (minn != INT_MAX)
            dp[i] = minn + 1;
        else
            dp[i] = -1;
    }
    return dp[amount];
}