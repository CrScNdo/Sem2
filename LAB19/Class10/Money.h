#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money {
    long rub;
    int penny;
public:
    Money() {rub = 0; penny = 0;};
    Money(long r, int p) {
        rub = r;
        penny = p;
    };
    Money(const Money& temp) {
        rub = temp.rub;
        penny = temp.penny;
    };
    ~Money() {};

    int get_rub() { return rub; };
    int get_penny() { return penny; };

    void set_rub(long r) { rub = r; }
    void set_penny(int p) { penny = p; }

    Money& operator =(const Money&);
    Money& operator ++();
    Money operator ++(int);
    Money operator +(const Money&);
    Money operator /(const Money& temp);
    Money operator *(double value) const;

    friend istream& operator >>(istream& in, Money& temp);
    friend ostream& operator <<(ostream& out, const Money& temp);
    
    friend fstream& operator >>(fstream &fin, Money &m);
    friend fstream& operator <<(fstream &fout, const Money &m);
};
