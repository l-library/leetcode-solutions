#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 时间复杂度为O(n*n)
// vector<int> twoSum(vector<int>& nums, int target) {
//   for (int i = 0; i < nums.size(); ++i)
//     for (int j = i + 1; j < nums.size(); ++j)
//       if (nums[i] + nums[j] == target) {
//         vector<int> result = {i, j};
//         return result;
//       }
//   vector<int> result = {};
//   return result;
// }

// 使用哈希表，时间复杂度为O(n)
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> search;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = search.find(target - nums[i]);
    if (it != search.end())  // 找到了
      return {it->second, i};
    search.insert({nums[i], i});  // key为值，value为下标
  }
  vector<int> result = {};
  return result;
}