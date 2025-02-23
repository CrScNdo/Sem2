#include <iostream>
#include <cmath>
using namespace std;
double S;

int find(double a, double b, double c)
{
    double p = (a+b+c)/2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    cout << "the area is equal to: " << S << endl;
    return S;
}

int square(int n, int d)
{
    double x = 3.14 / n;
    S = (n * pow(d, 2) / 4 * 1/tan(x));
    cout << "square " << n << " angle = " << S << endl;
    return S;
}

int main()
{
    int n, d;
    double a,b,c;
    S = 0;
    cout << "enter the 3 sides of the triangle" << endl;
    cin >> a >> b >> c;
    find (a,b,c);
    cout << "enter the number of sides of the n-gon" << endl;
    cin >> n;
    cout << "enter the side length of the correct n-gon" << endl;
    cin >> d;
    square(n, d);
    return 0;
}


