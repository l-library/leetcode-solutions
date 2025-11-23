struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ListNode *list_ptr1 = list1;
    ListNode *list_ptr2 = list2;
    ListNode *result;
    if (list1->val < list2->val)
    {
        result = list1;
        list_ptr1 = list_ptr1->next;
    }
    else
    {
        result = list2;
        list_ptr2 = list_ptr2->next;
    }
    ListNode *head = result;
    while (list_ptr1 && list_ptr2)
    {
        if (list_ptr1->val < list_ptr2->val)
        {
            result->next = list_ptr1;
            list_ptr1 = list_ptr1->next;
        }
        else
        {
            result->next = list_ptr2;
            list_ptr2 = list_ptr2->next;
        }
        result = result->next;
    }
    if (list_ptr1)
        result->next = list_ptr1;
    else
        result->next = list_ptr2;
    return head;
}