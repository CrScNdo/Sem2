#include <iostream>
using namespace std;

int main()
{
    int n, k, s;
    cout << "how many lines are there in total?" << endl;
    cin >> s;
    string* line = new string[s];
    cout << "enter a line and press enter for the next one" << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> line[i];
    }
    cout << "which line should I start deleting from?" << endl;
    cin >> n;
    cout << "how many lines to delete" << endl;
    cin >> k;
    if (n > s or k > s)
    {
        cout << "there is no such line" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << line[i] << endl;
        }
        for (int i = n + k; i < s; i++)
        {
            cout << line[i] << endl;
        }
    }
    delete[] line;
    return 0;
}

