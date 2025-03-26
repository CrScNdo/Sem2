#include <iostream>
using namespace std;

const int maxS = 100;
char Stack[maxS];
int top = -1;
int rev = 0;
int Size = 0;

void push(char n)
{
    if (top < maxS-1)
    {
        Stack[++top] = n;
        Size++;
    }
}

char peek()
{
    return (top>=0) ? Stack[top] : '\0';
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
    if(idx < 0 || idx > top)
    {
        return;
    }
    for(int i = idx; i < top; i++)
    {
        Stack[i] = Stack[i+1];
    }
    top--;
    Size--;
}

void insert(int idx, char n)
{
    if (idx < 0 || idx > top + 1 || top >= maxS - 1)
    {
        return;
    }
    for(int i = top; i >= idx; i--)
    {
        Stack[i+1] = Stack[i];
    }
    Stack[idx] = n;
    top++;
    Size++;
}

int main()
{
    int x;
    char n;
    int idx;
    cout << "How many words" << endl;
    cin >> x;
    cout << "Enter words" << endl;
    for(int i = 0; i < x; i++)
    {
        cin >> n;
        push(n);
    }
    cout << "Element on top " << peek() << endl;
    pop();
    while(top >= 0)
    {
        cout << "Next element " << peek() << endl;
        pop();
    }
    top += rev;
    rev = top;
    cout << "Element to delete" << endl;
    cin >> idx;
    del(idx);
    cout << "Element on top " << peek() << endl;
    pop();
    while(top >= 0)
    {
        cout << "Next element " << peek() << endl;
        pop();
    }
    top = Size-1;
    cout << "Index befor insert" << endl;
    cin >> idx;
    cout << "How many words" << endl;
    cin >> x;
    for(int j = 0; j < x; j++)
    {
        cin >> n;
        insert(idx, n);
        idx++;
    }
    cout << "Element on top " << peek() << endl;
    pop();
    while(top >= 0)
    {
        cout << "Next element " << peek() << endl;
        pop();
    }
    return 0;
}
