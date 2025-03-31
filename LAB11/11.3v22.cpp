#include <iostream>
using namespace std;

struct Stack
{
    struct Node
    {
        char data;
        Node* next;
        Node(char d, Node* n = nullptr) : data(d), next(n) {}
    };
    
    Node* top = nullptr;
    int Size = 0;
    
    void push(char n)
    {
        top = new Node(n, top);
        Size++;
    }
    
    char peek()
    {
        return (top) ? top->data : '\0';
    }
    
    void pop()
    {
        if (top)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
            Size--;
        }
    }
    
    void del(int idx)
    {
        if (idx < 0 || idx >= Size)
        {
            return;
        }
        
        if (idx == 0)
        {
            pop();
            return;
        }
        
        Node* prev = top;
        for (int i = 0; i < idx - 1; i++)
        {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        Size--;
    }
    
    void insert(int idx, char n)
    {
        if (idx < 0 || idx > Size)
        {
            return;
        }
        
        if (idx == 0)
        {
            push(n);
            return;
        }
        
        Node* prev = top;
        for (int i = 0; i < idx - 1; i++)
        {
            prev = prev->next;
        }
        prev->next = new Node(n, prev->next);
        Size++;
    }
    
    void print()
    {
        Node* temp = top;
        while (temp)
        {
            cout << "Next element " << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    
    ~Stack()
    {
        while (top)
        {
            pop();
        }
    }
};

int main()
{
    Stack s;
    int x;
    char n;
    int idx;
    
    cout << "How many words" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> n;
        s.push(n);
    }
    
    cout << "First element: ";
    s.print();
    
    cout << "Element to delete" << endl;
    cin >> idx;
    s.del(idx);
    cout << "Stack after deletion: ";
    s.print();
    
    cout << "Index before insert" << endl;
    cin >> idx;
    cout << "How many words" << endl;
    cin >> x;
    for (int j = 0; j < x; j++)
    {
        cin >> n;
        s.insert(idx, n);
        idx++;
    }
    
    cout << "Final stack: ";
    s.print();
    
    return 0;
}

