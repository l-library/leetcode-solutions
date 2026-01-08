#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> window;
    int left = 0;
    int right = 0;
    int max_length = 0;
    for (; right < s.size(); ++right)
    {
        if (window.find(s[right]) != window.end())
        {
            for (; left < right; ++left)
            {
                window.erase(s[left]);
                if (s[left] == s[right])
                {
                    left++;
                    break;
                }
            }
        }
        window.insert(s[right]);
        if (right - left + 1 > max_length)
            max_length = right - left + 1;
    }
    return max_length;
}

int main()
{
    string a = "abcabcbb";
    lengthOfLongestSubstring(a);
}