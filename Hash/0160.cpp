#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 遍历两个链表（时间复杂度为O(m*n)，空间复杂度为O(1))
ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB)
{
    ListNode *current_A = headA;
    ListNode *current_B = headB;
    while (current_A != NULL)
    {
        while (current_B != NULL)
        {
            if (current_B == current_A)
                return current_A;
            current_B = current_B->next;
        }
        current_A = current_A->next;
        current_B = headB;
    }
    return NULL;
}

// 利用哈希表
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *current_A = headA;
    unordered_set<ListNode *> set;
    // A中所有元素进入哈希表
    while (current_A != NULL)
    {
        set.insert(current_A);
        current_A = current_A->next;
    }
    ListNode *current_B = headB;
    while (current_B != NULL)
    {
        auto search = set.find(current_B);
        if (search != set.end())
            return current_B; // 找到了
        current_B = current_B->next;
    }
    return NULL;
}