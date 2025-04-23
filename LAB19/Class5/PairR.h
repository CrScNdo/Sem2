#pragma once
#include "Pair.h"
#include "Object.h"
#include "Vector.h"

class Rational :
public Pair
{
public:
    Rational(void);
    ~Rational(void);
    Rational(int, int);
    Rational(const Rational&);
    
    int get_num() {return num;}
    int get_den() {return den;}
    
    void set_num(int);
    void set_den(int);
    
    Rational operator-(const Rational& r);
    Rational operator+(const Rational& r);
    Rational operator*(const Rational& r);
    
    Rational& operator=(const Rational&);
    friend istream& operator>>(istream&in, Rational&r);
    friend ostream& operator<<(ostream&out, Rational&r);
    
protected:
    int num;
    int den;
};
