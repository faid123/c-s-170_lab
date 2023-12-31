#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
    struct Node
    {
        T data;
        Node* next;
    };
private:
    Node* pHead;

public:
    List(Node* node = nullptr)
    {
        pHead = node;
    }

    ~List() { clear(); }

    List& operator=(const List& node)
    {
        Node* curr = nullptr;

        if (this == &node)
            return *this;

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

    void push_back(T data)
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

    void push_front(T data)
    {
        if (!(pHead))
        {
            pHead = new Node;
            pHead->data = data;
            pHead->next = nullptr;
            return;
        }
        Node* curr = nullptr;
        curr = pHead;
        pHead = nullptr;
        pHead = new List::Node;
        pHead->next = curr;
        pHead->data = data;
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

    int getSize()
    {
        Node* curr = pHead;
        int size = 0;

        while (curr)
        {
            curr = curr->next;
            ++size;
        }
        return size;
    }

    T removeFront()
    {
        Node* tmp = nullptr;
        T value = 0;
        if (pHead)
        {
            tmp = pHead;
            value = pHead->data;
            pHead = pHead->next;
            delete tmp;
            tmp = nullptr;
        }
        return value;
    }
};

template <typename U>
class Stack : protected List<U>
{
public:
    void push(U v)
    {
        List<U>::push_front(v);
    }

    U pop() noexcept(false)
    {
        if (isEmpty())
            throw
            "Error";

        return List<U>::removeFront();
    }

    bool isEmpty() noexcept
    {
        return List<U>::getSize() == 0;
    }
};


int main() 
{
    Stack<int> s;
    std::cout << s.isEmpty();
    s.push(1);
    s.push(2);
    s.push(3);
    try {
        std::cout << s.pop();
        std::cout << s.pop();
        std::cout << s.pop();
        std::cout << s.pop();
    }
    catch (const char* msg) {
        std::cout << msg;
    }
    return 0;
}