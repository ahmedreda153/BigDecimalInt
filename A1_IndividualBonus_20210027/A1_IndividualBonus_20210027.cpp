#include <iostream>

using namespace std;

string DeleteSpaces(string str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }
    }
    return temp;
}

int main()
{
}