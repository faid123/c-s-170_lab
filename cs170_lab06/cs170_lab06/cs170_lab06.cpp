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

class List
{
public:
    struct Node
    {
        int data;
        Node* next;
    };
    Node* pHead;

    List(Node* node = nullptr)
    {
        pHead = node;
    }

    ~List() { clear(); }

    List(const List& node)
        : pHead(nullptr)
    {
        Node* curr = nullptr;

        curr = node.pHead;
        while (curr)
        {
            push_back(curr->data);
            curr = curr->next;
        }
    }

    List& operator=(const List& node)
    {
        Node* curr = nullptr;

        curr = node.pHead;
        while (curr)
        {
            push_back(curr->data);
            curr = curr->next;
        }
        return *this;
    }
    friend ostream& operator<<
        (ostream& out, const List& node)
    {
        if (!node.pHead)
        {
            out << endl;
            return out;
        }

        Node* curr = node.pHead;

        while (curr)
        {
            if (curr->next)
            {
                out << (curr->data)
                    << ",";
            }
            else
            {
                out << (curr->data)
                    << endl;
            }
            curr = curr->next;
        }
        curr = nullptr;
        return out;
    }

    void push_back(int data)
    {
        if (!(pHead))
        {
            pHead = DBG_NEW Node;
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
        curr->next = DBG_NEW Node;
        curr->next->data = data;
        curr->next->next = nullptr;
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
    List src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);

    List dst1(src);

    src.clear();

    List dst2;
    dst2 = dst1;

    std::cout << dst2;

    _CrtDumpMemoryLeaks();
    return 0;
}