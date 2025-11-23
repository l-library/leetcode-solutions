#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 初版，利用哈希表，时间复杂度O(n)，空间复杂度O(n)
bool hasCycle_(ListNode *head)
{
    if (!head || !head->next)
        return false;
    unordered_set<ListNode *> node_set;
    ListNode *current = head;
    while (current)
    {
        auto search = node_set.find(current);
        if (search != node_set.end())
            return true;
        node_set.insert(current);
        current = current->next;
    }
    return false;
}

// 快慢指针法，时间复杂度O(n)，空间复杂度O(1)
bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *slow = head;
    ListNode *quick = head->next;
    while (slow != quick && quick && quick->next)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    if (!quick || !quick->next)
        return false;
    return true;
}