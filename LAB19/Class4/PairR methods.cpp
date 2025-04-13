#include "PairR.h"

Rational::Rational(void):Pair()
{
    num = 0;
    den = 0;
}

Rational::~Rational(void)
{
    
}

Rational::Rational(int n, int d):Pair(n, d)
{
    num = n;
    den = d;
}

Rational::Rational(const Rational&r)
{
    num = r.num;
    den = r.den;
}

void Rational::set_num(int n)
{
    num = n;
}

void Rational::set_den(int d)
{
    den = d;
}

Rational Rational::operator-(const Rational& r)
{
    int t1 = num * r.den;
    int t2 = r.num * den;
    Rational temp2;
    temp2.num= t1 - t2;
    temp2.den = den * r.den;
    return temp2;
}

Rational Rational::operator+(const Rational& r)
{
    int t1 = num * r.den;
    int t2 = r.num * den;
    Rational temp2;
    temp2.num= t1 + t2;
    temp2.den = den * r.den;
    return temp2;
}

Rational Rational::operator*(const Rational& r)
{
    Rational temp2;
    temp2.num= num * r.num;
    temp2.den = den * r.den;
    return temp2;
}

Rational& Rational::operator=(const Rational&r)
{
    if(&r == this) return *this;
    num = r.num;
    den = r.den;
    return *this;
}

istream& operator>>(istream&in, Rational&r)
{
    cout << endl;
    cout << "Numerator: "; in>> r.num;
    cout << "Dominator: "; in>> r.den;
    return in;
}

ostream& operator<<(ostream&out, Rational&r)
{
    out<<"\nNumerator: " << r.num;
    out<<"\nDominator: " <<r.den;
    return out;
}


