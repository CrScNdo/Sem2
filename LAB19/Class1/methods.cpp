#include <iostream>
#include "Funk.h"

using namespace std;

void foundY::function(double x)
{
    y = (A * x) + B;
}

void foundY::show(double x)
{
    cout << "y для x = " << x << " равняется: " << y << endl;
}

double foundY::read()
{
    cin >> x;
    return x;
}
