struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head_c = slow;
    prev->next = nullptr;
    auto a = sortList(head);
    auto b = sortList(head_c);
    ListNode *new_list;
    auto a_c = a, b_c = b;
    if (a && b)
    {
        if (a->val < b->val)
        {
            new_list = a_c;
            a_c = a_c->next;
        }
        else
        {
            new_list = b_c;
            b_c = b_c->next;
        }
    }
    else if (a)
        return a;
    else
        return b;
    ListNode *new_list_c = new_list;
    for (; a_c != nullptr && b_c != nullptr;)
    {
        if (a_c->val < b_c->val)
        {
            new_list_c->next = a_c;
            a_c = a_c->next;
        }
        else
        {
            new_list_c->next = b_c;
            b_c = b_c->next;
        }
        new_list_c = new_list_c->next;
    }
    if (!a_c)
        new_list_c->next = b_c;
    else
        new_list_c->next = a_c;
    return new_list;
}