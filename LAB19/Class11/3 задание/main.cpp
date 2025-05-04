#include "Vector.h"
#include <iostream>
#include "/Users/aleksandrsadriev/Documents/Class11.2/Class11.2/Money.h"
#include "/Users/aleksandrsadriev/Documents/Class11.2/Class11.2/Money methods.cpp"

int main()
{
    Vector<Money>vec(5);
    vec.Print();
    Money min = vec.min();
    vec.Print();
    int tmp;
    cin >> tmp;
    vec.del(tmp);
    vec.Print();
    Money max = vec.max();
    Money sum = min + max;
    vec.add_to_all(sum);
    vec.Print();
    return 0;
}
