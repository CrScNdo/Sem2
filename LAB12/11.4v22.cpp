#include <iostream>
using namespace std;

struct Queue
{
    struct Node
    {
        char data;
        Node* next;
        Node(char d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* front = nullptr;
    Node* rear = nullptr;
    int Size = 0;

    void enqueue(char n)
    {
        Node* newNode = new Node(n);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        Size++;
    }

    void dequeue()
    {
        if (front)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
            Size--;
            if (!front) rear = nullptr;
        }
    }

    void print()
    {
        Node* temp = front->next;
        while (temp)
        {
            cout << endl << "Next element ";
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx >= Size)
        {
            return;
        }

        if (idx == 0)
        {
            dequeue();
            return;
        }

        Node* prev = front;
        for (int i = 0; i < idx - 1; i++)
        {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == rear)
        {
            rear = prev;
        }
        delete toDelete;
        Size--;
    }

    void insertAt(int idx, char n)
    {
        if (idx < 0 || idx > Size)
        {
            return;
        }

        Node* newNode = new Node(n);

        if (idx == 0)
        {
            newNode->next = front;
            front = newNode;
            if (!rear) rear = newNode;
        }
        else
        {
            Node* prev = front;
            for (int i = 0; i < idx - 1; i++)
            {
                prev = prev->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
            if (newNode->next == nullptr)
            {
                rear = newNode;
            }
        }
        Size++;
    }
};

int main()
{
    Queue q;
    int x, idx;
    char n;

    cout << "How many words?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> n;
        q.enqueue(n);
    }

    cout << "First element: ";
    cout << q.front->data;
    q.print();

    cout << "Index to delete: ";
    cin >> idx;
    q.deleteAt(idx);
    cout << "First element: ";
    cout << q.front->data;
    q.print();

    cout << "Index before insert: ";
    cin >> idx;
    cout << "How many words to insert?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for (int j = 0; j < x; j++)
    {
        cin >> n;
        q.insertAt(idx, n);
        idx++;
    }

    cout << "First element: ";
    cout << q.front->data;
    q.print();

    return 0;
}

