#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int range_min, range_max;
    int min;
    bool flag = false;
    range_min = 2;
    range_max = 280000;
    int n;
    cin >> n;
    int count = 0;
    int a[n];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    while (l < n)
    {
        min = a[l];
        for(int i = l+1; i < n; i++)
        {
            if(min > a[i])
            {
                min = a[i];
                count = i;
                flag = true;
            }
        }
        if (flag)
        {
            a[count] = a[l];
            a[l] = min;
        }
        flag = false;
        l++;
    }
    cout << "sorted" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
