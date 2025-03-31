#include <iostream>
using namespace std;

const int maxS = 100;

struct Stack
{
    char arr[maxS];
    int top = -1;
    int rev = 0;
    int Size = 0;

    void push(char n)
    {
        if (top < maxS - 1)
        {
            arr[++top] = n;
            Size++;
        }
    }

    char peek()
    {
        return (top >= 0) ? arr[top] : '\0';
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
            rev++;
        }
    }

    void del(int idx)
    {
        if (idx < 0 || idx > top)
        {
            return;
        }
        for (int i = idx; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }
        top--;
        Size--;
    }

    void insert(int idx, char n)
    {
        if (idx < 0 || idx > top + 1)
        {
            return;
        }
        for (int i = top; i >= idx; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[idx] = n;
        top++;
        Size++;
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
    
    cout << "Element on top " << s.peek() << endl;
    s.pop();
    
    while (s.top >= 0)
    {
        cout << "Next element " << s.peek() << endl;
        s.pop();
    }
    
    s.top += s.rev;
    s.rev = s.top;
    
    cout << "Element to delete" << endl;
    cin >> idx;
    s.del(idx);
    
    cout << "Element on top " << s.peek() << endl;
    s.pop();
    
    while (s.top >= 0)
    {
        cout << "Next element " << s.peek() << endl;
        s.pop();
    }
    
    s.top = s.Size - 1;
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
    
    cout << "Element on top " << s.peek() << endl;
    s.pop();
    
    while (s.top >= 0)
    {
        cout << "Next element " << s.peek() << endl;
        s.pop();
    }
    
    return 0;
}

