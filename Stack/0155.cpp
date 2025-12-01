#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int val = 0;
    int min_num = 0;
    Node *next = nullptr;
    Node(int x, int min_num_) : val(x), next(nullptr), min_num(min_num_) {}
    Node(int x, int min_num_, Node *next_) : val(x), min_num(min_num_), next(next_) {}
};

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (top_ == nullptr)
        {
            Node *new_node = new Node(val, val);
            top_ = new_node;
            return;
        }
        Node *new_node = new Node(val, min(val, top_->min_num));
        new_node->next = top_;
        top_ = new_node;
    }

    void pop()
    {
        Node *last = top_;
        top_ = top_->next;
        delete last;
    }

    int top()
    {
        return top_->val;
    }

    int getMin()
    {
        return top_->min_num;
    }

private:
    Node *top_ = nullptr;
};