#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    vector<ListNode *> every_node;
    ListNode *current = head;
    while (current)
    {
        every_node.push_back(current);
        current = current->next;
    }
    if (every_node.size() == n)
        return head->next;
    if (n == 1)
    {
        every_node[every_node.size() - 2]->next = nullptr;
        return head;
    }
    ListNode *left = every_node[every_node.size() - n - 1];
    ListNode *right = every_node[every_node.size() - n + 1];
    left->next = right;
    return head;
}