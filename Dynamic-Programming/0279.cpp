#include <cmath>
#include <vector>

using namespace std;

// 对于f(n)，其一定等于f(n-x^2)+1
int numSquares(int n)
{
    vector<int> arr(n + 1, INT_MAX);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int minn = INT_MAX;
        for (int j = 0; j * j <= i; ++j)
        {
            minn = min(minn, arr[i - j * j]);
        }
        arr[i] = minn + 1;
    }
    return arr[n];
}