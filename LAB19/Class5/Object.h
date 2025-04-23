#pragma once
#include <iostream>

using namespace std;

class Object
{
public:
    Object() {}
    ~Object() {}
    virtual void show() = 0;
};

