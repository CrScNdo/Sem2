#include <iostream>

using namespace std;

class Money
{
    int rub;
    int pen;
public:
    Money(void);
    Money(int, int);
    Money(const Money&);
    Money&operator=(const Money&);
    
    friend ostream&operator<<(ostream&out, const Money&m);
    friend istream&operator>>(istream&in, Money&m);
    
    Money operator+(const Money& m) const;
    
public:
    virtual ~Money(void);
};
