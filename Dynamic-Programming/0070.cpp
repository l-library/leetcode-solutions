#include <vector>

using namespace std;

int climbStairs(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int p = 0;
    int q = 1;
    int r = p + q;
    for (int i = 2; i <= n; ++i)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}