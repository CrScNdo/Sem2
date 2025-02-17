#include <iostream>
using namespace std;
int main()
{
    char eng[27] = {"abcdefghijklmnopqrstuvwxyz"};
    string rus[27] = {"э", "б", "c", "д", "е", "ф", "г", "x", "ай", "ж", "к", "л", "м", "н", "о", "п", "р", "р", "с","т", "ю", "в", "в", "x", "у", "з"};
    string a;
    int key;
    cout << "enter the string by replacing spaces with underscores and lowercase letters" << endl;
    cin >> a;
    cout << a << " -> ";
    for (size_t i = 0; i < a.length(); i++)
    {
        if (a[i] == '_')
        {
            cout << " ";
        }
        for(int j = 0; j < 27; j++)
        {
            if (a[i] == eng[j])
            {
                cout << rus[j];
            }
        }
    }
    cout << endl;
    cout << "is the pronunciation correct (1), if not, enter your own version" << endl;
    cin >> key;
    if (key == 1)
    {
        return 0;
    }
    else
    {
        cout << "thanks for your pronunciation" << endl;
    }
    return 0;
}

