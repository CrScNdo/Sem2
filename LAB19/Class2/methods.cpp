#include <iostream>
#include <string>
#include "Computer.h"

using namespace std;

Computer::Computer()
{
    cpu = "";
    ram = 0;
    memory = 0;
    cout << "Constructor without parameters for an object" << this << endl;
}

Computer::Computer(string c, int r, int m)
{
    cpu = c;
    ram = r;
    memory = m;
    cout << "Constructor with parameters for an object" << this << endl;
}

Computer::Computer(const Computer &PC)
{
    cpu = PC.cpu;
    ram = PC.ram;
    memory = PC.memory;
    cout << "Copy constructor for an object" << this << endl;
}

Computer::~Computer()
{
    cout << "The destructor for the object" << this << endl;
}

string Computer::get_cpu()
{
    return cpu;
}

int Computer::get_ram()
{
    return ram;
}

int Computer::get_memory()
{
    return memory;
}

void Computer::set_cpu(string c)
{
    cpu = c;
}

void Computer::set_ram(int r)
{
    ram = r;
}

void Computer::set_memory(int m)
{
    memory = m;
}

void Computer::show()
{
    cout << "CPU: " << cpu << endl;
    cout << "RAM: " << ram << endl;
    cout << "Memory: " << memory << endl;
}


