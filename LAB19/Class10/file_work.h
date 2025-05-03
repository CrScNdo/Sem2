#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* m)
{
    fstream stream(m, ios::out|ios::trunc);
    if(!stream) return -1;
    int n;
    Money p;
    cout << "N ?"; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p;
        stream << p << endl;
    }
    stream.close();
    return n;
}

int print_file(const char* f)
{
    fstream stream(f, ios::in);
    if(!stream) return -1;
    Money m;
    int i = 0;
    while(stream >> m)
    {
        cout << m << endl;
        i++;
    }
    stream.close();
    return i;
}

int del_file(const char* f_name, int k)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if(!stream) return -1;
    int i = 0;
    Money m;
    while(stream >> m)
    {
        if(stream.eof()) break;
        i++;
        if(i != k) temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int add_file(const char*f_name, int k, Money mm)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if(!stream) return -1;
    Money m;
    int i = 0, l = 0;
    while(stream >> m)
    {
        if(stream.eof()) break;
        i++;
        if(i == k)
        {
            temp << mm;
            l++;
        }
        temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}

int add_end(const char* f_name, Money mm)
{
    fstream stream(f_name, ios::app);
    if(!stream) return -1;
    stream << mm;
    return 1;
}

int change_file(const char*f_name, int k, Money mm)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    Money m;
    int i = 0, l = 0;
    char x;
    while(stream >> m)
    {
        if(stream.eof()) break;
        i++;
        if(i == k)
        {
            cout << m << " - is changing... Continue[y/n] ?" << endl;
            cin >> x;
            if(x == 'n' || x == 'N') break;
            temp << mm;
            l++;
        }
        else temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}
