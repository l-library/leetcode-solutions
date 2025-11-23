struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 遍历l1和l2
    ListNode *current_1 = l1;
    ListNode *current_2 = l2;
    // 存储结果
    ListNode *result = new ListNode; // 虚头节点
    ListNode *result_head = result;
    int carry = 0; // 存储进位
    while (current_1 || current_2 || carry)
    {
        // 向后遍历
        result->next = new ListNode;
        result = result->next;
        // 计算
        int num1 = current_1 ? current_1->val : 0;
        int num2 = current_2 ? current_2->val : 0;
        result->val = (num1 + num2 + carry) % 10;
        carry = (num1 + num2 + carry) / 10;
        // 继续向后
        if (current_1)
            current_1 = current_1->next;
        if (current_2)
            current_2 = current_2->next;
    }
    ListNode *excess = result_head;
    result_head = result_head->next;
    delete excess;
    return result_head;
}

int main()
{
    ListNode a(2);
    ListNode b(1, &a);
    ListNode c(8, &b);
    addTwoNumbers(&c, &b);
}