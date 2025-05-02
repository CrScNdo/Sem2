#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(int s, int k)
{
    if(s>MAX_SIZE) throw 1;
    size = s;
    data = new int[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = k;
    }
    beg.elem = &data[0];
    end.elem = &data[size];
}

Vector::Vector(Vector&a)
{
    size = a.size;
    data = new int[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
    beg.elem = &data[0];
    end.elem = &data[size];
}

Vector::~Vector()
{
    delete[] data;
    data = 0;
}

Vector&Vector::operator=(const Vector&a)
{
    if(this==&a) return *this;
    size=a.size;
    if(data != 0) delete[] data;
    data = new int[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
    beg.elem = &data[0];
    end.elem = &data[size];
    return *this;
}

int& Vector::operator[](int index)
{
    if (index < 0 || index >= size) throw 2;
    return data[index];
}

Vector Vector::operator+(int k)
{
    if(size+1==MAX_SIZE) throw 4;
    Vector temp(size);
    for(int i = 0; i < size; i++)
    {
        temp.data[i]+=data[i]+k;
    }
    return temp;
}


Vector Vector::operator--(int)
{
    if (size == 0)
    {
        cout << "Vector is already empty." << endl;
        return *this;
    }

    Vector temp(*this);

    size--;

    int* newData = new int[size];
    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;

    beg.elem = &data[0];
    end.elem = &data[size];

    return temp;
}

int Vector::len()
{
    return size;
}

int Vector::operator()()
{
    return len();
}

ostream&operator<<(ostream&out, Vector&a)
{
    for(int i = 0; i < a.len(); ++i)
    {
        out << a.data[i] << " ";
    }
    return out;
}

istream&operator>>(istream&in, Vector&a)
{
    for(int i = 0; i < a.len(); ++i)
    {
        in >> a.data[i];
    }
    return in;
}

Vector Vector::operator*(const Vector& v)
{
    int* temp = new int[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < v.size; j++)
        {
            if (data[i] == v.data[j])
            {
                bool alreadyExists = false;
                for (int k = 0; k < count; k++)
                {
                    if (temp[k] == data[i])
                    {
                        alreadyExists = true;
                        break;
                    }
                }

                if (!alreadyExists)
                {
                    temp[count++] = data[i];
                }
            }
        }
    }
    Vector result(count);
    for (int i = 0; i < count; i++)
    {
        result.data[i] = temp[i];
    }

    delete[] temp;

    if (count > 0)
    {
        cout << "Intersection: ";
        for (int i = 0; i < count; i++)
        {
            cout << result.data[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No intersection" << endl;
    }

    return result;
}
