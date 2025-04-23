#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector a(5);
    cout << a << endl;
    cin >> a;
    cout << a << endl;
    a[2] = 100;
    cout << a << endl;
    Vector b(10);
    cout << b << endl;
    Vector c(10);
    Vector d(10);
    d = a * b;
    c = b+100;
    cout << c << endl;
    cout << "The lenght of a = " << a() << endl;
    cout << *(a.first()) << endl;
    Iterator i = a.first();
    ++i;
    cout << *i << endl;
    for ( i=a.first(); i != a.last(); ++i)
    {
        cout << *i << endl;
    }
    return 0;
}
