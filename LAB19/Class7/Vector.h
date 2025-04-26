#include "Money.h"
#include <iostream>

using namespace std;

template <class T>
class Vector
{
    int size;
    int* data;
public:
    Vector(int s, T k);
    Vector(Vector<T>&a);
    ~Vector();
    Vector&operator=(const Vector<T>&a);
    T&operator[](int index);
    Vector operator+(T k);
    int operator()();
    int len();
    
    friend ostream&operator<<(ostream&out, Vector<T>&a)
    {
        for(int i = 0; i < a.len(); ++i)
        {
            out << a.data[i] << " ";
        }
        return out;
    }

    friend istream&operator>>(istream&in, Vector<T>&a)
    {
        for(int i = 0; i < a.len(); ++i)
        {
            in >> a.data[i];
        }
        return in;
    }
    
    Vector operator*(const Vector<T>&v);
};
