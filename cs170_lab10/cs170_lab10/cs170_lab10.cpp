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
    Node* pHead;

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
};

template <typename U>
class Stack : public List<U>
{
    List<U> list;
    List<U> tmp;

public:
    void push(U v) 
    {
        list.push_front(v);
    }

    U pop() noexcept(false)
    {
        if (isEmpty())
            throw 
            "Error: Stack is empty!\n";

        U value = 0;

        if (list.pHead)
        {
            //List<U>::Node* temp = nullptr;
            tmp = list;
            value = list.pHead->data;
            list.pHead = list.pHead->next;
            delete tmp.pHead;
            tmp.pHead = nullptr;
        }
        return value;
    }

    bool isEmpty() noexcept 
    {
        printempty();
        return list.getSize() == 0;
    }

    void printempty()
    {
        if (list.getSize() == 0)
            cout << "list empty" << endl;
        else
            cout << "list not empty" << endl;
    }

    void printlist()
    {
        cout << list;
    }
};

int main()
{
    Stack<int> s1;
    Stack<int> s11;

    cout << "---Stack s1---" << endl;
    try 
    {
        cout << s1.pop();
        cout << s1.isEmpty();
    }
    catch (const char *str)
    {
        cout << str;
    }
    s1.push(1);
    s11 = s1;
    s1.isEmpty();
    s1.pop();
    s1.push(2);
    s1.push(3);
    s1.printlist();
    try
    {
        cout << s1.pop();
        cout << " " << endl;
        cout << s1.pop();
        cout << " " << endl;
        cout << s1.pop();
    }
    catch (const char* str)
    {
        cout << str;
    }
    
    cout << "---Stack s11---" << endl;
    try
    {
        cout << s11.pop();
        cout << " " << endl;
        s11.isEmpty();
    }
    catch (const char* str)
    {
        cout << str;
    }

    Stack<float> s2;
    cout << "---Stack s2---" << endl;
    try
    {
        cout << s2.pop();
        cout << s2.pop();
    }
    catch (const char* str)
    {
        cout << str;
    }
    s2.push(1.5f);
    s2.isEmpty();
    s2.push(2.5f);
    s2.push(3.5f);
    s2.printlist();
    try
    {
        cout << s2.pop();
        cout << " " << endl;
        cout << s2.pop();
        cout << " " << endl;
        cout << s2.pop();
        cout << " " << endl;
        cout << s2.pop();
    }
    catch (const char* str)
    {
        cout << str;
    }

    return 0;
}