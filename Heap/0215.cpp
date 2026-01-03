#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, less<int>> heap;
    for (auto i : nums)
    {
        heap.push(i);
    }
    while (!heap.empty())
    {
        k--;
        if (k == 0)
            return heap.top();
        heap.pop();
    }
    return -1;
}