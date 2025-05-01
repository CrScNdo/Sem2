#pragma once

#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Event.h"

using namespace std;
class Vector
{
public:
    Vector();
    Vector(int);
    ~Vector(void);
    void Add(Object*);
    void Del();
    void Show();
    int operator()();
    void HandleEvent(const TEvent&e);
protected:
    Object**beg;
    int size;
    int cur;
};
