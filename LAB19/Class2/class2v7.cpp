#include <iostream>
#include <string>
#include "Computer.h"

using namespace std;

Computer make_computer()
{
    string c;
    int r, m;
    cout << "Enter CPU: ";
    cin >> c;
    cout << "Enter RAM: ";
    cin >> r;
    cout << "Enter memory: ";
    cin >> m;
    cout << endl;
    Computer t(c, r, m);
    return t;
}

void print_pc(Computer t)
{
    t.show();
}

int main()
{
    Computer t1;
    t1.show();
    Computer t2("R7", 8, 3);
    t2.show();
    Computer t3 = t2;
    t3.set_cpu("I7");
    t3.set_ram(16);
    t3.set_memory(5);
    print_pc(t3);
    t1 = make_computer();
    t1.show();
    return 0;
}

