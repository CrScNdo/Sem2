#include <iostream>
#include <cstdio>

using namespace std;

bool vowel(unsigned char first, unsigned char second)
{
    return (first == 0xD0 && (second == 0xB0 || second == 0xB5 || second == 0xB8 || second == 0xBE)) || (first == 0xD1 && (second == 0x91 || second == 0x83 || second == 0x8B || second == 0x8D || second == 0x8E || second == 0x8F));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned char first_byte, second_byte;
    int rh;
    int count = 1;
    int vowels = 0;
    int max = 0;
    int word = 0;
    string str;
    FILE* fp = fopen("/Users/aleksandrsadriev/Desktop/txt1.txt", "r");
    FILE* np = fopen("/Users/aleksandrsadriev/Desktop/new.txt", "r");
    while ((rh = fgetc(fp)) != EOF)
    {
        putchar(rh);
    }
    cout << endl << endl;
    cout << "Строки с двумя и более словами: " << endl << endl;
    rewind(fp);
    while ((rh = fgetc(fp)) != EOF)
    {
        str.clear();
        count = 0;
        while (rh != '\n' && rh != EOF)
        {
            if (rh == 32)
            {
                count++;
            }
            str += (char)rh;
            rh = fgetc(fp);
        }
        if (count > 2)
        {
            fputs(str.c_str(), np);
            fputs("\n", np);
        }
    }
    while ((rh = fgetc(np)) != EOF)
    {
        putchar(rh);
    }
    cout << endl;
    rewind(fp);
    count = 0;
    while ((rh = fgetc(fp)) != EOF)
    {
        rh = tolower(rh);
        if (rh == 32 || rh == '\n')
        {
            if (vowels > max)
            {
                max = vowels;
                word = count;
            }
            vowels = 0;
            count++;
            str.clear();
        }
        else
        {
            first_byte = rh;
            second_byte = fgetc(fp);
            if (vowel(first_byte, second_byte))
            {
                vowels++;
            }
        }
    }
    cout << endl;
    cout << "Самое большое число гласных в слове номер: " << word << endl;
    fclose(fp);
    return 0;
}

