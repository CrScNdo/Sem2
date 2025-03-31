#include <iostream>

using namespace std;
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
    if( idx < 0 || idx > Size)
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
    if( idx < 0 || idx > Size)
    {
        return;
    }
    for (int i = Size; i > idx; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[top-idx+1] = n;
    Size++;
    top++;
}

int main()
{
    char n;
    int x, idx;
    cout << "How many words?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for(int i = x-1; i >= 0; i--)
    {
        cin >> n;
        arr[i] = n;
        top++;
        Size++;
    }
    cout << "First element ";
    print();
    cout << endl;
    while(top >= 0)
    {
        cout << "Next element ";
        print();
        cout << endl;
    }
    top = Size-1;
    cout << "Index to delete" << endl;
    cin >> idx;
    deleteAt(idx);
    cout << "First element ";
    print();
    cout << endl;
    while(top >= 0)
    {
        cout << "Next element ";
        print();
        cout << endl;
    }
    top = Size-1;
    cout << "Insert before elemenr with index ?" << endl;
    cin >> idx;
    cout << "How many elements to insert?" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for(int i = 0; i < x; i++)
    {
        cin >> n;
        insertAt(n, idx);
    }
    cout << "First element ";
    print();
    cout << endl;
    while(top >= 0)
    {
        cout << "Next element ";
        print();
        cout << endl;
    }
    return 0;
}
