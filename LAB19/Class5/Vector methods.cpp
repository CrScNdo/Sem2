#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(void){
    ptr = 0;
    size = 0;
    cur = 0;
}

Vector::~Vector(void){
    if(ptr != 0)
    {
        delete[] ptr;
    }
    ptr = 0;
}

Vector::Vector(int n){
    ptr = new Object * [n];
    cur = 0;
    size = n;
}

void Vector::Add(Object* v){
    if(cur < size)
    {
        ptr[cur] = v;
        cur++;
    }
}

ostream& operator <<(ostream& out, Vector& v){
    if(v.size == 0)
    {
        out << "Empty" << endl;
    }
    Object** p = v.ptr;
    for(int i = 0; i < v.cur; i++)
    {
        (*p)->show();
        p++;
    }
    return out;
}
