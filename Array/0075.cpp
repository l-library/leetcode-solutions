#include <vector>
#include <algorithm>

using namespace std;
// 0,0,1
void sortColors(vector<int> &nums)
{
    if (nums.empty() || nums.size() == 1)
        return;
    int left = 0;
    int right = nums.size() - 1;
    for (int i = 0; i <= right; ++i)
    {
        if (nums[i] == 0)
            swap(nums[i], nums[left++]);
        else if (nums[i] == 2)
            swap(nums[i--], nums[right--]);
    }
}