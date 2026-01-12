#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    if (temperatures.empty())
        return {};
    vector<int> stk_val(temperatures.size(), 0);
    vector<int> stk_index(temperatures.size(), 0);
    int top = 0;
    vector<int> result(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); ++i)
    {
        if (top == 0)
        {
            stk_val[top] = temperatures[i];
            stk_index[top] = i;
            top++;
            continue;
        }
        if (temperatures[i] > stk_val[top - 1])
        {
            while (top > 0 && temperatures[i] > stk_val[top - 1])
            {
                top--;
                result[stk_index[top]] = i - stk_index[top];
            }
            stk_val[top] = temperatures[i];
            stk_index[top] = i;
            top++;
        }
        else
        {
            stk_val[top] = temperatures[i];
            stk_index[top] = i;
            top++;
        }
    }
    return result;
}

int main()
{
    vector<int> a = {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTemperatures(a);
}