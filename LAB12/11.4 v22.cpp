#include <iostream>

using namespace std;

struct Stack
{
    char arr[100];
    int top = -1;
    int Size = 0;

    void print()
    {
        cout << arr[top] << " ";
        top--;
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx > Size)
        {
            return;
        }

        for (int i = top - idx; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }
        top--;
        Size--;
    }

    void insertAt(char n, int idx)
    {
        if (idx < 0 || idx > Size)
        {
            return;
        }
        idx = (top - idx + 1 + Size) % Size;
        for (int i = Size; i > idx; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[idx] = n;
        Size++;
        top++;
        }
};

int main()
{
    Stack s;
    char n;
    int x, idx;
    
    cout << "How many words?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for (int i = x - 1; i >= 0; i--)
    {
        cin >> n;
        s.arr[i] = n;
        s.top++;
        s.Size++;
    }
    
    cout << "First element ";
    s.print();
    cout << endl;
    
    while (s.top >= 0)
    {
        cout << "Next element ";
        s.print();
        cout << endl;
    }
    
    s.top = s.Size - 1;
    cout << "Index to delete" << endl;
    cin >> idx;
    s.deleteAt(idx);
    
    cout << "First element ";
    s.print();
    cout << endl;
    
    while (s.top >= 0)
    {
        cout << "Next element ";
        s.print();
        cout << endl;
    }
    
    s.top = s.Size - 1;
    cout << "Insert before element with index ?" << endl;
    cin >> idx;
    cout << "How many elements to insert?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    
    for (int i = 0; i < x; i++)
    {
        cin >> n;
        s.insertAt(n, idx);
    }
    
    cout << "First element ";
    s.print();
    cout << endl;
    
    while (s.top >= 0)
    {
        cout << "Next element ";
        s.print();
        cout << endl;
    }
    
    return 0;
}
