#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> s;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < nums.size() && right > left)
        {
            if (nums[left] + nums[right] > -num)
                right--;
            else if (nums[left] + nums[right] < -num)
                left++;
            else
            {
                vector<int> a = {num, nums[left], nums[right]};
                if (s.find(a) == s.end())
                {
                    result.push_back(a);
                    s.insert(a);
                }
                left++;
            }
        }
    }
    return result;
}