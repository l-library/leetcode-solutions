#include <string>
#include <stack>

using namespace std;

bool isMate(char a, char b)
{
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
        return true;
    return false;
}

bool isValid(string s)
{
    stack<char> signs;
    for (size_t i = 0; i < s.size(); ++i)
    {
        char current_char = s[i];
        if (signs.empty())
        {
            signs.push(current_char);
            continue;
        }
        if (isMate(signs.top(), current_char))
        {
            signs.pop();
        }
        else
            signs.push(current_char);
    }
    if (signs.empty())
        return true;
    return false;
}