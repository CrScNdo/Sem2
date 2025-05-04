#include <iostream>
#include "/Users/aleksandrsadriev/Documents/Class11.2/Class11.2/Money.h"
#include "/Users/aleksandrsadriev/Documents/Class11.2/Class11.2/Money methods.cpp"
#include <vector>
#include <stack>
#include "Vector.h"

int main()
{
    Vector<Money>v(3);
    v.Print();
    Money min = v.min();
    v.Print();
    int tmp;
    cin >> tmp;
    v.del(tmp);
    v.Print();
    Money max = v.max();
    Money sum = min + max;
    v.add_to_all(sum);
    v.Print();
    return 0;
}
