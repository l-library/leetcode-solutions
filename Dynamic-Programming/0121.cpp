#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int result = 0;
    int min = INT_MAX;
    for (int i = 0; i < prices.size(); ++i)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            continue;
        }
        if (prices[i] - min > result)
            result = prices[i] - min;
    }
    return result;
}