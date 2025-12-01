#include <iostream>
#include <unordered_set>

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

// 方法一：哈希表 O(N) O(N)
Node *detectCycle_(Node *head)
{
    if (!head)
        return nullptr;
    Node *current = head;
    std::unordered_set<Node *> set;
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
Node *detectCycle(Node *head)
{
    if (!head)
        return nullptr;
    Node *fast = head;
    Node *slow = head;
    while (fast && slow)
    {
        if (!fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            Node *current = head;
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