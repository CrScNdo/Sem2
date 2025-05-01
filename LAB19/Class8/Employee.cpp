#include "Employee.h"
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Employee::Employee(void):Person()
{
    post = "";
}

Employee::~Employee(void)
{}

Employee::Employee(string n, int a, string p) : Person(n, a)
{
    post = p;
}

Employee::Employee(const Employee&e)
{
    name = e.name;
    age = e.age;
    post = e.post;
}

void Employee::set_post(string p)
{
    post = p;
}

Employee& Employee::operator=(const Employee&e)
{
    if(&e == this) return *this;
    name = e.name;
    age = e.age;
    post = e.post;
    return *this;
}

void Employee::Show()
{
    cout << "Name: " << name;
    cout << endl;
    cout << "Age: " << age;
    cout << endl;
    cout << "Post: " << post;
    cout << endl;
    cout << endl;
}

void Employee::Input()
{
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Post: "; cin >> post;
    cout << endl;
}
