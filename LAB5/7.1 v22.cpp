#include <iostream>
using namespace std;

int find ( int n, int * a, int count)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 != 0)
        {
            count++;
        }
    }
    cout << "odd numbers: " << count << endl;
    return count;
}

int find( string b, int counter)
{
    for(size_t i = 0; i < size(b); i++)
    {
        if (b[i] == ' ')
        {
            counter++;
        }
    }
    cout << "number of words: " << counter << endl;
    return counter;
}

int main()
{
    int n;
    int count = 0;
    cout << "enter the number of numbers" << endl;
    cin >> n;
    int a[n];
    cout << "enter the numbers" << endl;
    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    find(n, a, count);
    int counter = 1;
    string b;
    cout << "enter the line" << endl;
    cin >> b;
    getline(cin, b);
    find(b, counter);
    return 0;
}

