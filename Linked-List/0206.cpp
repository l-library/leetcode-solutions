struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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