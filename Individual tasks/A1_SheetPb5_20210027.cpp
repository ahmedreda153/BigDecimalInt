// FCAI - OOP - 2022 - Assignment 1
// Program Name: pronlem 5 dominochain
// Program Description: check if we could make a domino chain or not
// Last Modification Date: 13/10/2022
// author / ID : Ahmed Alaa Mohamed / 20210027
// Under The Supervision of: Dr. Mohamed El-Ramly
#include <iostream>
#include <vector>
using namespace std;

struct dimont
{
    int leftdots;
    int rightdots;
};

vector<dimont> result;
// vector<dimont> result2;
bool check = false;

// the main algorithm
bool dominchain(vector<dimont> &domino)
{
    for (size_t i = 0; i < domino.size() - 1; i++)
    {
        if (domino[i].rightdots == domino[i + 1].leftdots)
            check = true;
        if (check)
            continue;
        else
            break;
    }
    if (check)
        return true;
    else
        return false;
}

bool major(int lastdots, vector<dimont> &dominos)
{
    if (dominos.empty())//check if the program ended
    {
        return true;
    }
    else
    {
        for (int i = 0; i < dominos.size(); i++)
        {
            dimont game = dominos[i];// equal it with first domino
            vector<dimont> rest = dominos;//make a new vector which i can delete from it
            rest.erase(rest.begin() + i);//earse frist domino which in " dimont game"

            if (lastdots == 17 || lastdots == game.leftdots)//last dots == 17 will use for the first time only
            {
                result.push_back(game);
                if (major(game.rightdots, rest))//recursion
                {
                    return true;
                }
            }

            if (lastdots == 17 || lastdots == game.rightdots)
            {
                result.push_back(game);
                if (major(game.leftdots, rest))//recursion
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool chain(vector<dimont> &dominos)
{
    return major(17, dominos);//17 it's just for getting first domino and we can use any number
}

int main()
{
    vector<dimont> dominos = {{2,6}, {1,4}, {4, 4}, {6, 1}, {4, 3}}; // test
    int x = chain(dominos);
    cout << x;
    cout << endl;
    // if we find a domino chain
    if (x == 1)
    {
        for (int i = result.size() - dominos.size(); i < result.size(); i++)
        {
            cout << result[i].leftdots << "|" << result[i].rightdots << " ";
        }
        cout << endl;
    }
    //if we didn't find domino chain
    else
    {
        return 0;
    }
}