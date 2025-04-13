#include <iostream>
#include <string>
#pragma once

using namespace std;

class Computer
{
    string cpu;
    int ram;
    int memory;
public:
    Computer();
    Computer(string, int, int);
    Computer(const Computer&);
    ~Computer();
    string get_cpu();
    void set_cpu(string);
    int get_ram();
    void set_ram(int);
    int get_memory();
    void set_memory(int);
    void show();
};
