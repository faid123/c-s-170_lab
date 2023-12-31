#include <iostream>

using namespace std;

namespace DP
{
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head = nullptr;

    void print(Node* node)
    {
        while (node)
        {
            if (node->next)
                cout << (node->data) << ",";
            else
                cout << (node->data);

            node = node->next;
        }
    }
}

using namespace DP;

int main()
{
    int data = 0;
    Node* node = nullptr;
    Node* curr = nullptr;

    while (++data < 4)
    {
        node = new Node;
        node->data = data;
        node->next = nullptr;
        if (!head)
            head = node;
        else
            curr->next = node;

        curr = node;
    }

    print(head);

    while (head)
    {
        node = node->next;
        delete head;
        head = node;
    }
    head = NULL;

    return 0;
}