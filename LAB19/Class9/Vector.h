#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Iterator
{
    friend class Vector;
    int* elem;
public:
    Iterator(){ elem = 0; }
    Iterator(const Iterator&it) { elem = it.elem; }
    bool operator==(const Iterator&it) { return elem==it.elem; }
    bool operator!=(const Iterator&it) { return elem!=it.elem; }
    
    void operator++() { ++elem; }
    void operator--() { --elem; }
    int&operator *() const { return*elem; }
};

class Vector
{
    int size;
    int* data;
    Iterator beg;
    Iterator end;
public:
    Vector() { size = 0; data = 0; }
    Vector(int s, int k = 0);
    Vector(Vector&a);
    ~Vector();
    Vector&operator=(const Vector&a);
    int&operator[](int index);
    Vector operator+(int k);
    Vector operator--(int);
    int operator()();
    int len();
    
    friend ostream& operator<<(ostream& out, Vector&a);
    friend istream& operator>>(istream& in, Vector&a);
    
    Vector operator*(const Vector& v);
    
    Iterator first() { return beg; }
    Iterator last() { return end; }
};
