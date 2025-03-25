#include <iostream>
using namespace std;
int listSize = 0;

struct list {
    char data;
    list* nptr;
    list* pptr;
};

list* push_back(list * head, char data, list *& tail)
{
    if (listSize == 0)
    {
        listSize++;
        tail = new list {data, nullptr, nullptr};
        return tail;
    }
    else
    {
        list* current = head;
        while (current->nptr != nullptr)
        {
            current = current->nptr;
        }
        tail = current->nptr = new list{data, nullptr, current};
        listSize++;
        return head;
    }
}

void print(list * head)
{
    list * current = head;
    while(current)
    {
        cout << current->data << " ";
        current = current->nptr;
    }
}

void printBack(list * tail)
{
    list * current = tail;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->pptr;
    }
    cout << endl;
}

list* deleteAt(list * head, list * tail, int del)
{
    list * current;
    list * curr;
    if(del == 0)
    {
        current = head;
        head = head->nptr;
        head->pptr = nullptr;
        delete current;
        listSize--;
        return head;
    }
    else if(del == listSize-1)
    {
        current = tail->pptr;
        curr = tail;
        current->nptr = nullptr;
        delete curr;
        return head;
    }
    else
    {
        current = head;
        for(int i = 0; i < del; i++)
        {
            current = current->nptr;
        }
        list * next = current->nptr;
        list * prev = current->pptr;
        delete current;
        current = prev;
        current->nptr = next;
        current = next;
        current->pptr = prev;
        listSize--;
        return head;
    }
}

list * addPrev(list * head, list * tail, int idx, char words)
{
    list * current;
    list * prev = head;
    list * next = head;
    if(idx == 0)
    {
        head = new list(words, head, nullptr);
        return head;
    }
    else
    {
        for(int i = 0; i < idx-1; i++)
        {
            prev = prev->nptr;
        }
        for(int i = 0; i < idx; i++)
        {
            next = next->nptr;
        }
        current = new list(words, next, prev);
        next->pptr = current;
        prev->nptr = current;
        return head;
    }
}

int main()
{
    int n, del, add, idx;
    char data, words;
    list* head = nullptr;
    list* tail = nullptr;
    cout << "how many words to write?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        head = push_back(head, data, tail);
    }
    print(head);
    cout << endl;
    printBack(tail);
    cout << "Number of word to delete" << endl;
    cin >> del;
    if (del > listSize-1 || del < 0)
    {
        cout << "Wrong number" << endl;
    }
    else
    {
        head = deleteAt(head, tail, del);
        print(head);
    }
    cout << endl;
    cout << "Insert before word with index ?" << endl;
    cin >> idx;
    cout << "How many words" << endl;
    cin >> add;
    if(idx < 0 || idx > listSize)
    {
        cout << "Wrong index" << endl;
    }
    else
    {
        for(int i = 0; i < add; i++)
        {
            cout << "Enter word" << endl;
            cin >> words;
            head = addPrev(head, tail, idx, words);
        }
    }
    print(head);
    return 0;
}
