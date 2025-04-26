#include <iostream>
#include "Money.h"

using namespace std;

Money::Money(void)
{
    rub = pen = 0;
}

Money::Money(int r, int p)
{
    rub = r;
    pen = p;
}

Money::Money(const Money&m)
{
    rub = m.rub;
    pen = m.pen;
}

Money::~Money(void)
{
    
}

Money&Money::operator=(const Money&m)
{
    rub = m.rub;
    pen = m.pen;
    return*this;
}

ostream& operator<<(ostream& out, const Money& m)
{
    out << m.rub << ",";
    if (m.pen < 10)
        out << "0";
    out << m.pen;
    return out;
}

istream&operator>>(istream&in, Money&m)
{
    cout << "rub? "; in >> m.rub;
    cout << "pen? "; in >> m.pen;
    return in;
}

Money Money::operator+(const Money& m) const
{
    int t1 = rub * 100 + pen;
    int t2 = m.rub * 100 + m.pen;
    Money temp2;
    temp2.rub = (t1 + t2) / 100;
    temp2.pen = (t1 + t2) % 100;
    return temp2;
}

