#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    try
    {
        Vector x(2, 3);
        Vector y;
        cout << x;
        cout << endl;
        cout << "Nomer ?";
        cout << endl;
        int i;
        cin >> i;
        cout << x[i] << endl;
        y = x+3;
        cout << y;
        x--;
        cout << x;
        x--;
        cout << endl;
    }
    catch(int)
    {
        cout << "Error" << endl;
    }
    return 0;
}
