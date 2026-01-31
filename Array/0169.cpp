#include <vector>
#include <stack>

using namespace std;

int majorityElement(vector<int> &nums)
{
    stack<int> stk;
    for (auto num : nums)
    {
        if (stk.empty() || stk.top() == num)
            stk.push(num);
        else
            stk.pop();
    }
    return stk.top();
}