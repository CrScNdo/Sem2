#include <iostream>
using namespace std;
const int maxim = 100;

int average(int n, int a[][maxim])
{
    int avg = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            avg += a[j][i];
        }
        avg /= n;
        if (i != n-1)
        {
            cout << "avg " << i+1 << ":" << avg << endl;
        }
        for (int k = 0; k < n; k++)
        {
            if (a[k][i] > avg)
            {
                count++;
            }
        }
    }
    cout << "Above avarage: " << count << endl;
    return count;
}

int main()
{
    int range_min, range_max;
    range_min = 2;
    range_max = 280000;
    int n;
    cin >> n;
    cout << endl;
    int a[maxim][maxim];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    average(n, a);
    return 0;
}


