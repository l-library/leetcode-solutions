#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

bool isNum(char ch)
{
    return ch >= '0' && ch <= '9';
}

string helper(string s, int left, int right)
{
    string result;
    if (s.empty() || left > right)
        return "";
    for (int i = left; i <= right; ++i)
    {
        if (isNum(s[i]))
        {
            int num = 0;
            int j = i;
            while (isNum(s[j]))
                j++;
            stack<char> ch_stack;
            int k = j;
            for (; k < right; ++k)
            {
                if (s[k] == '[')
                    ch_stack.push(s[k]);
                else if (s[k] == ']')
                {
                    ch_stack.pop();
                    if (ch_stack.empty())
                        break;
                }
            }
            string a = helper(s, j + 1, k - 1);
            j--;
            while (i <= j)
            {
                num += (s[i] - '0') * pow(10, j - i);
                i++;
            }
            for (int p = 0; p < num; ++p)
                result += a;
            i = k;
        }
        else
            result += s[i];
    }
    return result;
}

string decodeString(string s)
{
    return helper(s, 0, s.size() - 1);
}

int main()
{
    cout << decodeString("100[leetcode]");
    return 0;
}