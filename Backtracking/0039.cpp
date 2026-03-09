#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> &candidates, int target, int i, vector<vector<int>> &res, vector<int> &candidate)
{
    if (i >= candidates.size())
        return;
    if (target == 0)
    {
        res.push_back(candidate);
        return;
    }
    helper(candidates, target, i + 1, res, candidate);
    int num = candidates[i];
    if (target - num >= 0)
    {
        candidate.push_back(num);
        helper(candidates, target - num, i, res, candidate);
        candidate.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> candidate;
    helper(candidates, target, 0, res, candidate);
    return res;
}