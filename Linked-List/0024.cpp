struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    ListNode *next = head->next;
    ListNode *next_head = swapPairs(next->next);
    next->next = head;
    head->next = next_head;
    return next;
}