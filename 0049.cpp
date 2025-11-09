#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> map;
    for (auto word : strs)
    {
        string key = word;
        sort(key.begin(), key.end()); // 将key内字母排序
        map[key].emplace_back(word);
    }
    for (auto i = map.begin(); i != map.end(); ++i)
        result.emplace_back(i->second);
    return result;
}