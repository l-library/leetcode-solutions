#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 初版，类似冒泡排序
void moveZeroes_(vector<int> &nums)
{
    int count_zero = 0;
    for (int i = 0; i < nums.size() - count_zero; ++i)
        if (nums[i] == 0)
        {
            for (int j = i; j < nums.size() - 1; ++j)
                swap(nums[j], nums[j + 1]);
            --i;
            count_zero++;
        }
}

// 第二版，时间复杂度为O(n)
void moveZeroes(vector<int> &nums)
{
    int length = nums.size();
    int left = 0;
    int right = 0;
    while (right != length)
    {
        if (nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}