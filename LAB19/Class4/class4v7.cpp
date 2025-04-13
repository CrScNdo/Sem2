#include <iostream>
#include "PairR.h"

using namespace std;

int main()
{
    Pair a, c, d;
    cin >> a;
    cout << a;
    Pair b(4, 5);
    cout << b;
    cout << endl;
    c = a - b;
    cout << "\nSubtraction" << c << endl;
    d = a * b;
    cout << "\nMultiplication" << d << endl;
    cout << endl << "Comparison"; 
    a == b;
    Rational A, C;
    cin >> A;
    Rational B(7, 2);
    cout << A;
    cout << B;
    C = A - B;
    cout << endl << "\nSubtraction";
    cout << C << endl;
    C = A + B;
    cout << endl << "\nAddition";
    cout << C << endl;
    C = A * B;
    cout << endl << "\nMultiplication";
    cout << C << endl;
    return 0;
}
