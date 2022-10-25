#include <iostream>
#include <map>
#include <iomanip>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    map<string, pair<int, int>> wordsMap; // map contain words, phrases, words point and number of occurrence of each word
    string message = " ";
    char temp[50];
    wordsMap[" bank "] = make_pair(3, 0);
    wordsMap[" withdraw "] = make_pair(3, 0);
    wordsMap[" account "] = make_pair(2, 0);
    wordsMap[" verification required "] = make_pair(2, 0);
    wordsMap[" financial "] = make_pair(2, 0);
    wordsMap[" free gift "] = make_pair(2, 0);
    wordsMap[" credit "] = make_pair(2, 0);
    wordsMap[" paypal "] = make_pair(2, 0);
    wordsMap[" sign up free "] = make_pair(1, 0);
    wordsMap[" verify "] = make_pair(1, 0);
    wordsMap[" atm "] = make_pair(3, 0);
    wordsMap[" free trial "] = make_pair(1, 0);
    wordsMap[" cash "] = make_pair(2, 0);
    wordsMap[" payment "] = make_pair(2, 0);
    wordsMap[" follow the link "] = make_pair(2, 0);
    wordsMap[" password "] = make_pair(2, 0);
    wordsMap[" warning "] = make_pair(1, 0);
    wordsMap[" earn money "] = make_pair(2, 0);
    wordsMap[" offer "] = make_pair(1, 0);
    wordsMap[" refund "] = make_pair(1, 0);
    wordsMap[" ebay "] = make_pair(2, 0);
    wordsMap[" bill "] = make_pair(1, 0);
    wordsMap[" unusual log in activity "] = make_pair(2, 0);
    wordsMap[" access "] = make_pair(1, 0);
    wordsMap[" buy "] = make_pair(1, 0);
    wordsMap[" change your password "] = make_pair(2, 0);
    wordsMap[" amazon "] = make_pair(2, 0);
    wordsMap[" visit here to get your reward "] = make_pair(1, 0);
    wordsMap[" alert "] = make_pair(2, 0);
    wordsMap[" click here "] = make_pair(3, 0);

    fstream file;
    char fileName[70];
    cin.getline(fileName, 70); // there is a file for test, file name is (temp.txt)

    file.open(fileName, ios::in);
    if (!file)
    {
        cout << "error";
        exit(0);
    }
    else
    {
        while (file >> temp)
        {
            message += temp;
            message += " ";
        }
        message += " ";
    }

    for (int i = 0; i < message.length(); i++)
    {
        message[i] = tolower(message[i]);
    }

    for (auto it = wordsMap.begin(); it != wordsMap.end(); it++)
    {
        string strFromMap = it->first;
        int pos = message.find(strFromMap, 0);
        while (pos != -1)
        {
            pos = message.find(strFromMap, pos + 1);
            it->second.second++;
        }
    }
    int sum = 0;
    cout << left << setw(30) << "Words/Phrases" << setw(15) << "Total Points";
    cout << setw(15) << "No. of occur." << endl << endl;
    for (auto it = wordsMap.begin(); it != wordsMap.end(); it++)
    {
        if (it->second.second != 0)
        {
            cout << left << setw(35) << it->first << setw(15) << it->second.second * it->second.first;
            cout << setw(10) << it->second.second << endl;
            sum += (it->second.first * it->second.second);
        }
    }
    cout << endl << "Total points of all message is " << sum;
}