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

// 不用set排除重复
vector<vector<int>> threeSum_1(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
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
                result.push_back({num, nums[left], nums[right]});
                while (left + 1 < right && nums[left + 1] == nums[left])
                {
                    left++;
                }
                while (right - 1 > left && nums[right - 1] == nums[right])
                {
                    right--;
                }
                left++;
            }
        }
    }
    return result;
}