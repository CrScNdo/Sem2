#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Vector
{
public:
    Object** ptr;
    int size, cur;
    Vector(void);
    Vector(int);
    ~Vector(void);
    void Add(Object*);
    friend ostream& operator <<(ostream& out, Vector&);
};
