#include <iostream>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：哈希表 O(N) O(N)
ListNode *detectCycle_(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *current = head;
    std::unordered_set<ListNode *> set;
    while (current != nullptr)
    {
        if (set.find(current) != set.end())
            return current;
        set.insert(current);
        current = current->next;
    }
    return nullptr;
}
// 方法二 快慢指针
ListNode *detectCycle(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && slow)
    {
        if (!fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            ListNode *current = head;
            while (current != slow)
            {
                slow = slow->next;
                current = current->next;
            }
            return slow;
        }
    }
    return nullptr;
}