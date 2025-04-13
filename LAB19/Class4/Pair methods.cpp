#include <iostream>
#include "Pair.h"

Pair::Pair(void)
{
    first = 0;
    second = 0;
}

Pair::~Pair(void)
{
    
}

Pair::Pair(int f, int s)
{
    first = f;
    second = s;
}

Pair::Pair(const Pair& pair)
{
    first = pair.first;
    second = pair.second;
}

void Pair::set_first(int f)
{
    first = f;
}

void Pair::set_second(int s)
{
    second = s;
}

Pair& Pair::operator=(const Pair&p)
{
    if(&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

Pair Pair::operator -(const Pair& p)
{
    int t1 = first;
    int t2 = second;
    int t3 = p.first;
    int t4 = p.second;
    Pair temp2;
    temp2.first = t1 - t2;
    temp2.second = t3 - t4;
    return temp2;
}

Pair Pair::operator *(const Pair& p)
{
    int t1 = first;
    int t2 = second;
    int t3 = p.first;
    int t4 = p.second;
    Pair temp2;
    temp2.first = t1 * t2;
    temp2.second = t3 * t4;
    return temp2;
}

void Pair::operator ==(const Pair& p)
{
    int t1 = first;
    int t2 = second;
    int t3 = p.first;
    int t4 = p.second;
    if(t1 == t2) { cout << endl << t1 << " and " << t2 << " Equal"; }
    else { cout << endl << t1 << " and " << t2 << " Not equal"; }
    if(t3 == t4) { cout << endl << t3 << " and " << t4 << " Equal" << endl; }
    else { cout << endl << t3 << " and " << t4 << " Not equal" << endl; }
}

istream& operator>>(istream&in, Pair&p)
{
    cout << "First: "; in >>p.first;
    cout << "Second: "; in >>p.second;
    return in;
}

ostream& operator<<(ostream&out, Pair&p)
{
    out <<"\nFirst: " << p.first;
    out <<"\nSecond: " << p.second;
    return out;
}

