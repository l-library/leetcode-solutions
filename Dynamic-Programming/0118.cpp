#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    if (!numRows)
        return {};
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; ++i)
        res[i].resize(i + 1, 0);
    res[0][0] = 1;
    for (int i = 1; i < numRows; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            res[i][j] = (j - 1 >= 0 ? res[i - 1][j - 1] : 0) + (j < i ? res[i - 1][j] : 0);
        }
    }
    return res;
}