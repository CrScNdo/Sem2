#include "Vector.h"
#include "Event.h"
#include <iostream>

using namespace std;

Vector::~Vector()
{
    if (beg != nullptr) {
        for (int i = 0; i < cur; ++i) {
            delete beg[i];
        }
        delete[] beg;
        beg = nullptr;
    }
}

Vector::Vector()
{
    beg = nullptr;
    cur = 0;
    size = 0;
}

Vector::Vector(int n)
{
    beg = new Object*[n];
    cur = 0;
    size = n;
}

void Vector::Add(Object*p)
{
    cout << "1.Person" << endl;
    cout << "2.employee" << endl;
    
    int y;
    cin >> y;
    if(y == 1)
    {
        Person*a=new(Person);
        a->Input();
        p = a;
        
        if(cur<size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    else
    {
        if(y == 2)
        {
            Employee *e = new Employee;
            e->Input();
            p = e;
            if(cur<size)
            {
                beg[cur] = p;
                cur++;
            }
            else return;
        }
    }
}

void Vector::Show()
{
    if(cur == 0) cout << "Empty"<<endl;
    Object**p = beg;
    for(int i = 0; i < cur; i++)
    {
        (*p)->Show();
        p++;
    }
}

int Vector::operator()()
{
    return cur;
}

void Vector::Del()
{
    if(cur == 0) return;
    cur--;
}

void Vector::HandleEvent(const TEvent&e)
{
    if(e.what == evMessage)
    {
        Object**p = beg;
        for(int i = 0; i < cur; i++)
        {
            (*p)->HandleEvent(e);
            p++;
        }
    }
}

