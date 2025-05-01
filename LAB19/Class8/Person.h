#pragma once
#include "Object.h"
#include "Event.h"
#include <string>
#include <iostream>

using namespace std;

class Person : public Object
{
public:
    Person(void);
    virtual ~Person(void);
    void Show();
    void Input();
    Person(string, int);
    Person(const Person&);
    string get_name();
    int get_age();
    void set_name(string);
    void set_age(int);
    Person& operator=(const Person&);
    void HandleEvent(const TEvent &e);
protected:
    string name;
    int age;
};
