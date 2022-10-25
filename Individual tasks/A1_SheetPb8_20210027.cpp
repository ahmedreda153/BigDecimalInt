// FCAI - OOP - 2022 - Assignment 1
// Program Name: pronlem 8
// Program Description: smart array
// Last Modification Date: 22/10/2022
// author / ID : Ahmed Alaa Mohamed / 20210027
// Under The Supervision of: Dr. Mohamed El-Ramly
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template <typename Temp>class Sarray
{
private:
    Temp *pointer;
    int size;

public:
    Sarray(Temp arr[], int length)
    {
        pointer = new Temp[length];
        size = length;
        for (int i = 0; i < size; i++)
        {
            pointer[i] = arr[i];
        }
    }
    Sarray(const Sarray &obj)
    {
        pointer = new Temp[obj.size];
        size = obj.size;
        for (int i = 0; i < size; i++)
        {
            pointer[i] = obj.pointer[i];
        }
    }
    Sarray &operator=(const Sarray &obj)
    {
        if (this != &obj)
        {
            delete[] pointer;
            pointer = new Temp[obj.size];
            size = obj.size;
            for (int i = 0; i < size; i++)
            {
                pointer[i] = obj.pointer[i];
            }
        }
        return *this;
    }
    int Size()
    {

        return size;
    }
    int &operator[](int len)
    {
        if (len >= size)
        {
            cout << "Invalid index, exiting";
            exit(0);
        }
        return pointer[len];
    }
    ~Sarray() { delete (pointer); };
};
int main()
{
    int x[] = {1, 2, 3};
    Sarray<int> arr(x, 3);
    cout << arr.Size() << endl;
    for (int i = 0; i < arr.Size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    Sarray<int> copy(arr);
    for (int i = 0; i < copy.Size(); i++)
    {
        cout << copy[i] << ' ';
    }
    cout << endl;
    Sarray<int> copy2 = arr;
    for (int i = 0; i < copy2.Size(); i++)
    {
        cout << copy2[i] << ' ';
    }
}