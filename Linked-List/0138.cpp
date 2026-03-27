#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> map;
    Node *previous = nullptr;
    Node *head_copy = nullptr;
    for (Node *current = head; current != NULL; current = current->next)
    {
        Node *new_node = new Node(current->val);
        if (!previous)
        {
            previous = new_node;
            head_copy = previous;
        }
        else
        {
            previous->next = new_node;
            previous = new_node;
        }
        map.emplace(current, new_node);
    }
    for (Node *current = head; current != NULL; current = current->next)
    {
        map[current]->random = map[current->random];
    }
    return head_copy;
}

int main()
{
    Node a(1);
    Node b(2);
    Node c(3);
    a.next = &b;
    b.next = &c;
    copyRandomList(&a);
    return 0;
}