#include <vector>
#include <string>

using namespace std;

vector<string> helper(string digits, int cur)
{
    if (digits.size() == 0)
        return {};
    char ch = (digits[cur] - '2') * 3 + 'a';
    int flag = 0;
    if (digits[cur] == '7')
        flag++;
    else if (digits[cur] == '8')
        ch++;
    else if (digits[cur] == '9')
    {
        ch++;
        flag++;
    }
    if (cur == digits.size() - 1)
    {
        vector<string> last;
        for (int i = 0; i < 3 + flag; ++i)
            last.push_back(string(1, static_cast<char>(ch + i)));
        return last;
    }
    auto last = helper(digits, cur + 1);
    int siz = last.size();
    for (int i = 0; i < siz; ++i)
    {
        for (int j = 0; j < 2 + flag; ++j)
        {
            auto eve = last.at(i);
            eve.insert(0, 1, static_cast<char>(ch + j));
            last.push_back(eve);
        }
        last.at(i).insert(0, 1, static_cast<char>(ch + 2 + flag));
    }
    return last;
}

vector<string> letterCombinations(string digits)
{
    return helper(digits, 0);
}