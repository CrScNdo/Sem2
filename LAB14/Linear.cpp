#include <iostream>

using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main()
{
    int m;
    cout << "How many numbers" << endl;
    cin >> m;
    int arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter number to find" << endl;
    int x;
    cin >> x;
    int res = search(arr, arrLength, x);
    if (res == -1) cout << "Element " << x << " not found" << endl;
    else cout << "Element " << x << " on index " << res << endl;
    return 0;
}
