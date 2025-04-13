#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
    Money A, B, C, D, E;
    double val;
    cin >> A >> B;
    cout << "Enter value to multiply on: ";
    cin >> val;
    cout << A << endl;
    C = (A) + B;
    D = A / B;
    E = C * val;
    
    cout << "Money1 = " << A << endl;
    cout << "Money2 = " << B << endl;
    cout << "Summ = " << C << endl;
    cout << "Division = " << D << endl;
    cout << "Multiplication = " << E << endl;
    return 0;
}
