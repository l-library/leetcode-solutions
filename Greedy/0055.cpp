#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    int right = nums.size() - 1;
    for (int i = right - 1; i >= 0; --i)
        if (nums[i] >= right - i)
            right = i;
    if (right == 0)
        return true;
    else
        return false;
}