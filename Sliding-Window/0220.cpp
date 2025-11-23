#include <algorithm>
#include <limits>
#include <set>
#include <vector>

using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                   int valueDiff) {
  set<long long> window;  // 利用滑动窗口查找，窗口内元素有序，满足第一个条件
  for (size_t i = 0; i < nums.size(); ++i) {
    set<long long>::iterator it = window.lower_bound(
        max(nums[i], INT_MIN + valueDiff) -
        valueDiff);  // 查找窗口中第一个大于等于当前值-t的元素
    if (it != window.end() &&
        *it <= min(nums[i], INT_MAX - valueDiff) +
                   valueDiff)  // 找到了且小于等于当前元素+t
      return true;
    // 窗口向后移动
    window.insert(nums[i]);
    if (i >= indexDiff) window.erase(nums[i - indexDiff]);
  }
  return false;
}