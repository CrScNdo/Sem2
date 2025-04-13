#pragma once
#include <iostream>

using namespace std;

class Pair
{
public:
    Pair(void);
    virtual ~Pair(void);
    Pair(int, int);
    Pair(const Pair&);
    
    int get_first() {return first;}
    int get_second() {return second;}
    
    void set_first(int);
    void set_second(int);
    
    Pair& operator = (const Pair&);
    
    Pair operator-(const Pair& p);
    Pair operator*(const Pair& p);
    void operator==(const Pair& p);
    
    friend istream& operator>>(istream&in, Pair&p);
    friend ostream& operator<<(ostream&out, Pair&p);
    
protected:
    int first;
    int second;
};
