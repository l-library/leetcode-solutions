#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 初版，栈实现
bool isPalindrome_(ListNode *head)
{
    if (!head || !head->next)
        return true;
    stack<int> stk;
    stk.push(head->val);
    ListNode *current = head;
    int size = 0;
    while (current)
    {
        current = current->next;
        size++;
    }
    current = head;
    for (int i = 0; i < size / 2; ++i)
    {
        stk.push(current->val);
        current = current->next;
    }
    if (size % 2 != 0)
        current = current->next;
    while (current)
    {
        if (current->val != stk.top())
            return false;
        current = current->next;
        stk.pop();
    }
    return true;
}

// 快慢指针+反转链表
// 反转链表 from 206
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr) // 空链表
        return nullptr;
    ListNode *current = head;
    ListNode *last_node = nullptr;
    while (current != nullptr)
    {
        ListNode *next = current->next;
        current->next = last_node;
        last_node = current;
        current = next;
    }
    return last_node;
}
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;
    ListNode *quick = head;
    ListNode *slow = head;
    ListNode *prev = quick;
    // slow指向中央/后半部分第一个节点
    while (quick && quick->next)
    {
        slow = slow->next;
        prev = quick;
        quick = quick->next->next;
    }
    if (!quick)             // 如果有偶数个节点
        quick = prev->next; // 回溯到尾节点
    else                    // 奇数个节点
        slow = slow->next;
    reverseList(slow); // 反转slow后面的节点，quick为反转后的头节点
    ListNode *current = head;
    while (quick && current)
    {
        if (quick->val != current->val)
            return false;
        quick = quick->next;
        current = current->next;
    }
    return true;
}