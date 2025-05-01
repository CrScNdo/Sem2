#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include "Dialog.h"

using namespace std;

int main()
{
    Dialog D;
    D.Execute();
    
    Person *p = new Person;
    p->Input();
    p->Show();
    
    Employee *e = new Employee;
    e->Input();
    e->Show();
    
    Vector v(10);
    Object* l = p;
    v.Add(l);
    l = e;
    v.Add(l);
    v.Show();
    v.Del();
    cout << endl;
    cout << "Vector size = " << v();
    cout << endl;
    
    return 0;
}
