#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector<int> a(5, 0);
    cout << a << endl;
    cin >> a;
    cout << a << endl;
    a[2] = 100;
    cout << a << endl;
    Vector<int> b(10, 1);
    cout << b << endl;
    Vector<int> c(10, 0);
    Vector<int> d(10, 0);
    d = a * b;
    if (d.len() > 0)
    {
        cout << "Intersection: " << d << endl;
    }
    else
    {
        cout << "No intersection" << endl;
    }

    c = b+100;
    cout << c << endl;
    cout << "The lenght of a = " << a() << endl;
    
    Money m;
    cin >> m;
    cout << m;
    cout << endl;
    Money k;
    cin >> k;
    cout << k;
    cout << endl;
    Money p;
    p = m + k;
    cout << p;
    cout << endl;
    return 0;
}
