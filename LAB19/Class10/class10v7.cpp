#include <iostream>
#include "Money.h"
#include <fstream>
#include <string>
#include "file_work.h"

using namespace std;

int main()
{
    Money x, m1, m2;
    int k, c;
    char file_name[30];
    do
    {
        cout << "n1. Make file" << endl;
        cout << "n2. Print file" << endl;
        cout << "n3. Delete record from file" << endl;
        cout << "n4. Add record to file" << endl;
        cout << "n5. Change record in file" << endl;
        cout << "n0. Exit" << endl;
        cin >> c;
        switch(c)
        {
            case 1:
                cout << "file name ?" << endl;
                cin >> file_name;
                k = make_file(file_name);
                if(k < 0) cout << "Can't make file";
                break;
            case 2:
                cout << "file name ?" << endl;
                cin >> file_name;
                k = print_file(file_name);
                if(k == 0) cout << "Empty file" << endl;
                if (k < 0) cout << "Can't read file" << endl;
                break;
            case 3:
                cout << "file name ?" << endl;
                cin >> file_name;
                int nom;
                cout << "nom ?" << endl;
                cin >> nom;
                k = del_file(file_name, nom);
                if(k < 0) cout << "Can't read file";
                break;
            case 4:
                cout << "file name ?" << endl;
                cin >> file_name;
                cout << "nom ?";
                cin >> nom;
                cout << "New money: ";
                cin >> m1;
                k = add_file(file_name, nom, m1);
                if(k < 0) cout << "Can't read file" << endl;
                if(k == 0) k=add_end(file_name, m1);
                break;
            case 5:
                cout << "file name ?" << endl;
                cin >> file_name;
                cout << "nom ?";
                cin >> nom;
                cout << "New money: ";
                cin >> m2;
                k = change_file(file_name, nom, m2);
                if(k < 0) cout << "Can't read file";
                if(k == 0) cout <<"Not such record";
                break;
        }
    }
    while(c != 0);
        
    return 0;
}
