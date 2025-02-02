#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int range_min, range_max;
    range_min = 2;
    range_max = 280000;
    int n, tmp;
    cin >> n;
    int count = n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    while (n > 0)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (a[i] > a[i+1])
            {
                tmp = a[i+1];
                a[i+1] = a[i];
                a[i] = tmp;
            }
        }
        n--;
    }
    cout << "sorted" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

