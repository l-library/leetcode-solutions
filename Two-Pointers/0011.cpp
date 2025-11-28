#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
    if (height.size() < 2)
        return 0;
    int left = 0, right = height.size() - 1; // 初始化双指针
    int max_water = 0;                       // 初始化最大盛水
    while (right > left)
    {
        int current = min(height[left], height[right]) * (right - left);
        if (current > max_water)
            max_water = current;
        if (height[left] < height[right]) // 移动高度较小的指针位置
            left++;
        else
            right--;
    }
    return max_water;
}

int main()
{
    vector<int> a = {1, 2, 1};
    maxArea(a);
    return 0;
}