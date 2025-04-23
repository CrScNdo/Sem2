#include <iostream>
#include "PairR.h"

using namespace std;

int main()
{
    Pair ex, tmp;
    cin >> ex >> tmp;
    cout << ex << endl;
    Object* v;
    v = &ex;
    v->show();
    
    Vector vec(5);
    Pair Tmp;
    vec.Add(v);
    v = &tmp;
    vec.Add(v);
    cout << endl << "Print vector:" << endl;
    cout << vec;
    cout << endl;
    
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
