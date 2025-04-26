#include "Vector.h"
#include <iostream>

using namespace std;

template <class T>
Vector<T>::Vector(int s, T k)
{
    size = s;
    data = new T[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = k;
    }
}

template <class T>
Vector<T>::Vector(Vector<T>&a)
{
    size = a.size;
    data = new T[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
    data = 0;
}

template <class T>
Vector<T>&Vector<T>::operator=(const Vector<T>&a)
{
    if(this==&a) return *this;
    size=a.size;
    if(data != 0) delete[] data;
    data = new T[size];
    for(int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
    return *this;
}

template <class T>
T& Vector<T>::operator[](int index)
{
    static T dummy = T();
    if(index < size)
    {
        return data[index];
    }
    else
    {
        cout << "\nError! Index > size\n";
        return dummy;
    }
}

template <class T>
Vector<T> Vector<T>::operator+(T k)
{
    Vector<T> temp(size, T());
    for(int i = 0; i < size; i++)
    {
        temp.data[i]=data[i]+k;
    }
    return temp;
}

template <class T>
int Vector<T>::len()
{
    return size;
}

template <class T>
int Vector<T>::operator()()
{
    return len();
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& v)
{
    T* temp = new T[size];
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

    Vector<T> result(count, T());
    for (int i = 0; i < count; i++)
    {
        result.data[i] = temp[i];
    }

    delete[] temp;

    return result;
}

template class Vector<int>;
