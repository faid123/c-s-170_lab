#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

using namespace std;

namespace List
{
    struct Node
    {
        int data;
        Node* next;
    };

    void print(Node* node)
    {
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
    }

    void push_front(Node** node,
        int data)
    {
        if (!(*node))
        {
            *node = new List::Node;
            (*node)->data = data;
            (*node)->next = nullptr;
            return;
        }
        Node* curr = nullptr;
        curr = *node;
        *node = nullptr;
        *node = new List::Node;
        (*node)->next = curr;
        (*node)->data = data;
    }

    void push_back(Node** node,
        int data)
    {
        if (!(*node))
        {
            *node = new List::Node;
            (*node)->data = data;
            (*node)->next = nullptr;
            return;
        }
        Node* curr = nullptr;
        curr = *node;

        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new List::Node;
        curr->next->data = data;
        curr->next->next = nullptr;
    }

    void clear(Node** node)
    {
        Node* curr = nullptr;
        Node* next = nullptr;
        curr = *node;

        while (curr->next)
        {
            next = curr->next;
            delete curr;
            curr = nullptr;
            curr = next;
        }
        delete curr;
        *node = nullptr;
    }
}

int main() {
    List::Node* pHead = nullptr;
    List::print(pHead);
    List::push_front(&pHead, 1);
    List::print(pHead);  //1
    List::push_front(&pHead, 2);
    List::print(pHead);  //2,1
    List::push_back(&pHead, 3);
    List::print(pHead);  //2,1,3
    List::push_back(&pHead, 4);
    List::print(pHead);  //2,1,3,4
    // Remove all nodes from the list
    List::clear(&pHead);
    List::print(pHead);

    _CrtDumpMemoryLeaks();

    return 0;
}