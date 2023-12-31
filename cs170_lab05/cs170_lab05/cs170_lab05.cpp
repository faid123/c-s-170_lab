#include <iostream>

using namespace std;

class List
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* pHead;

public:
    List() :pHead(this->pHead = nullptr) { }
    ~List() { clear(); }

    void print()
    {
        Node* node = pHead;
        if (!node)
        {
            cout << endl;
            return;
        }

        while (node)
        {
            if (node->next)
                cout << (node->data)
                << ",";
            else
            {
                cout << (node->data)
                    << endl;
                return;
            }
            node = node->next;
        }
        node = pHead;
    }

    void push_back(int data)
    {
        if (!(pHead))
        {
            pHead = new Node;
            (pHead)->data = data;
            (pHead)->next = nullptr;
            return;
        }
        Node* curr = nullptr;
        curr = pHead;

        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node;
        curr->next->data = data;
        curr->next->next = nullptr;
    }

    void insertAfter(int index, int data)
    {
        Node* curr = pHead;
        Node* next = nullptr;
        int counter = 0;

        if (index < 0)
            return;

        while (curr->next)
        {
            curr = curr->next;
            ++counter;
        }

        if (counter < index)
            return;

        curr = pHead;
        ++index;
        while (--index)
        {
            curr = curr->next;
        }
        next = new Node;
        next->data = data;
        next->next = curr->next;
        curr->next = next;
    }

    void remove(int index)
    {
        Node* curr = pHead;
        Node* next = nullptr;
        int counter = 0;

        if (index < 0)
            return;
        else if (!index)
        {
            next = curr->next;
            delete curr;
            curr = nullptr;
            pHead = next;
            return;
        }

        while (curr->next)
        {
            curr = curr->next;
            ++counter;
        }

        if (counter < index)
            return;

        curr = pHead;
        while (index--)
        {
            next = curr;
            curr = next->next;
        }
        next->next = curr->next;
        delete curr;
        curr = nullptr;

    }

    void clear()
    {
        Node* curr = pHead;
        Node* next = nullptr;

        while (curr)
        {
            next = curr->next;
            delete curr;
            curr = nullptr;
            curr = next;
        }
        delete curr;
        pHead = nullptr;
    }
};

int main()
{
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Do not insert when index is
    //   out of range
    list.insertAfter(-100, 20);
    list.insertAfter(100, 20);

    // Insert as a new 3rd element
    list.insertAfter(1, 20);

    // Remove 2nd element 
    list.remove(1);
    list.print();

    return 0;
}