#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int dis = p.size() - 1;
    if (dis > s.size() - 1)
        return {};
    vector<int> count(26, 0);
    for (auto i : p)
    {
        count[i - 'a']++;
    }
    // 初始化滑动窗口
    vector<int> slid(26, 0);
    for (int i = 0; i <= dis; ++i)
    {
        slid[s[i] - 'a']++;
    }
    if (slid == count)
        res.push_back(0);
    for (int left = 0, right = dis + 1; right < s.size(); ++left, ++right)
    {
        slid[s[left] - 'a']--;
        slid[s[right] - 'a']++;
        if (slid == count)
            res.push_back(left + 1);
    }
    return res;
}

int main()
{
    findAnagrams("cbaebabacd", "abc");
}