// FCAI - OOP - 2022 - Assignment 1
// Program Name: problem 0 earse spaces
// Program Description: erase spaces 
// Last Modification Date: 11/10/2022
// author / ID : Ahmed Alaa Mohamed / 20210027
// Under The Supervision of: Dr. Mohamed El-Ramly
#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string nstr;

    for (int i = 0; i < str.length();)
    {

        if (str[i] == ' ')
        {

            if (i == 0 || i == str.length() - 1)// because we can have a space in begin or end of string
            {
                i++;
                continue;
            }

            while (str[i + 1] == ' ')// after first space prgoram found after every word , program blinds every space to the next character
                i++;
        }

        nstr += str[i++];// program add character to new string and one space after every word
    }
    for (auto &c : nstr)
    {
        c = tolower(c);//make all sentence lower character
    }
    nstr[0] = toupper(nstr[0]);//make the first character upper

    cout << "New String: " << nstr;
    return 0;
}