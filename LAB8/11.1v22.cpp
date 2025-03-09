#include<iostream>

using namespace std;

class List
{
public:
    List();
    
    void print();
    void push_back(char data);
    void push_front(char data);
    int getsize() {return size;}
    void removeAt(int index);
    void insert(char data, int index);
    void pop_front();
    char& operator[](const int index);
    void clear();
    
private:
    class Node
    {
    public:
        Node *pNext;
        char data;
        Node(char data = char(), Node *pNext = nullptr) // char() - чтобы передавался не мусор
        {
            this->data = data;
            this->pNext = pNext;
        };
    };
    int size;
    Node *head;
    
};

List::List()
{
    size = 0;
    head = nullptr;
}

void List::push_back(char data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}

void List::push_front(char data)
{
    head = new Node(data, head);
    size++;
}

char & List::operator[](const int index)
{
    int count = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (count == index)
        {
            return current->data;
        }
        current = current->pNext;
        count++;
    }
    char expression;
    return expression;
}

void List::removeAt(int index)
{
   if (index == 0)
   {
       pop_front();
   }
   else
   {
       Node *previous = this->head;
       for (int i = 0; i < index-1; i++)
       {
           previous = previous->pNext;
       }
       Node *toDelete = previous->pNext;
       previous->pNext = toDelete->pNext;
       delete toDelete;
       size--;
   }
}

void List::insert(char data, int index)
{
    if(index == 0)
    {
        push_front(data);
    }
    else
    {
        Node *previous = this->head;
        for (int i = 0; i < index; i++)
        {
            previous = previous->pNext;
        }
        Node *newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        size++;
    }
}

void List::pop_front()
{
    Node *tmp;
    tmp = head->pNext;
    delete head;
    head = tmp;
    size--;
}

void List::clear()
{
    while(size)
    {
        pop_front();
    }
}

int main()
{
    int n, index;
    char data;
    List lst;
    cout << "Enter number of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        lst.push_back(data);
    }
    cout << "Elements: " << endl;
    for(int i = 0; i < lst.getsize(); i++)
    {
        cout << lst[i] << ", ";
    }
    cout << endl;
    cout << "enter the number you want to delete" << endl;
    cin >> index;
    if (index > lst.getsize() || index < 0)
    {
        cout << "No such number" << endl;
    }
    else
    {
        lst.removeAt(index);
        for(int i = 0; i < lst.getsize(); i++)
        {
            cout << lst[i] << ", ";
        }
    }
    cout << endl << "How many values to insert" << endl;
    cin >> n;
    cout << "Enter which item to insert before the number" << endl;
    cin >> index;
    cout << "Enter value" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        lst.insert(data, index-1);
    }
    for(int i = 0; i < lst.getsize(); i++)
    {
        cout << lst[i] << ", ";
    }
    lst.clear();
    return 0;
}
