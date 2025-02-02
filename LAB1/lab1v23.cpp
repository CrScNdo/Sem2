#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int range_min, range_max, max;
    int scor, n;
    int count = -1;
    int tmp = 0;
    range_min = 2;
    range_max = 280000;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    max = a[0];
    int rol;
    cout << "right(1) or left(2)" << endl;
    cin >> rol;
    switch(rol)
    {
        default:
        {
            cout << "wrong choise" << endl;
            return 0;
        }
        case(1):
        {
            cout << "circle right" << endl;
            cin >> scor;
            for (int j = scor; j < n; j++)
            {
                cout << a[j] << " ";
                tmp++;
            }
            for (int j = 0; j < n - tmp; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
            for (int i = 1; i < n; i++)
            {
                if (max < a[i])
                {
                    max = a[i];
                    
                }
            }
            cout << "max " << max << " count " << count+1 << endl;
            for (int i = 0; i < 8; i++)
            {
                if (max == a[i])
                {
                    count++;
                }
                else if(count >= 1)
                {
                    for (int j = i-1; j < n-count;j++)
                    {
                        a[j] = a[j+1];
                        a[j+1] = 0;
                        
                    }
                }
            }
            cout << "deleted if count > 0" << endl;
            n = n - count;
            for (int i=0; i<n;i++)
            {
                cout << a[i] << " ";
            }
            return 0;
        }
        case(2):
        {
            cout << "circle left" << endl;
            cin >> scor;
            for (int j = scor; j > -1; j--)
            {
                cout << a[j] << " ";
                tmp++;
            }
            for (int j = n-1; j > scor; j--)
            {
                cout << a[j] << " ";
            }
            cout << endl;
            for (int i = 1; i < n; i++)
            {
                if (max < a[i])
                {
                    max = a[i];
                    
                }
            }
            cout << "max " << max << " count " << count+1 << endl;
            for (int i = 0; i < 8; i++)
            {
                if (max == a[i])
                {
                    count++;
                }
                else if(count >= 1)
                {
                    for (int j = i-1; j < n-count;j++)
                    {
                        a[j] = a[j+1];
                        a[j+1] = 0;
                        
                    }
                }
            }
            cout << "deleted if count > 0" << endl;
            n = n - count;
            for (int i=0; i<n;i++)
            {
                cout << a[i] << " ";
            }
            return 0;
        }
    }
    
}
