#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    vector<vector<int>> res(intervals.size());
    for (auto &i : res)
    {
        i.resize(2);
    }
    // 升序排序
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b)
         { return a[0] < b[0]; });
    auto back = res.begin();
    *back = intervals[0];
    for (auto it = std::next(intervals.begin()); it != intervals.end(); ++it)
    {
        if ((*back)[1] < (*it)[0])
            *(++back) = *it;
        else if ((*back)[1] > (*it)[1])
            ;
        else
            (*back)[1] = (*it)[1];
    }
    for (auto it = res.end() - 1; it != res.begin(); --it)
    {
        if ((*it)[0] == 0 && (*it)[1] == 0)
            res.resize(res.size() - 1);
    }
    return res;
}