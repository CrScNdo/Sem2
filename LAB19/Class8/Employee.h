#pragma once
//
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

class Employee : public Person
{
    string post;
public:
    Employee(void);
    ~Employee(void);
    void Show();
    void Input();
    Employee(string, int, string);
    Employee(const Employee&);
    string get_post() { return post; }
    void set_post(string);
    Employee& operator=(const Employee&);
};
