#include <iostream>
#include <string>
#include "Person.h"
#include "Event.h"

using namespace std;

Person::Person(void)
{
    name = "";
    age = 0;
}

Person::~Person(void)
{}

Person::Person(string n, int a)
{
    name = n;
    age = a;
}

Person::Person(const Person& p)
{
    name = p.name;
    age = p.age;
}


string Person::get_name()
{
    return name;
}

int Person::get_age()
{
    return age;
}

void Person::set_name(string n)
{
    name = n;
}

void Person::set_age(int a)
{
    age = a;
}

Person& Person::operator=(const Person&p)
{
    if(&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show()
{
    cout << "Name: " << name;
    cout << endl;
    cout << "Age: " << age;
    cout << endl;
    cout << endl;
}

void Person::Input()
{
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << endl;
}

void Person::HandleEvent(const TEvent &e)
{
    if(e.what == evMessage)
    {
        switch(e.command)
        {
            case cmGet:
                cout << "Name =" << get_name() << endl;
                break;
        }
    }
}
