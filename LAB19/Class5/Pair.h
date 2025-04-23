#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Pair : public Object
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
    
    void show() override {
            cout << "Pair: (" << first << ", " << second << ")" << endl;
        }
    
protected:
    int first;
    int second;
};
