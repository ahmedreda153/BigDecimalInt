#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void binaryprint(int n) // Part (A) in problem 4
{
    if (n == 0)
    {
        cout << 0;
        return;
    }
    else if (n == 1)
    {

        cout << n % 2;
        return;
    }
    else if (n > 1)
    {
        binaryprint(n / 2);
        cout << n % 2;
    }
}

void numbers(string prefix, int k) // Part (B) in problem 4
{
    if (k == 0)
    {
        cout << prefix;
        return;
    }
    else
    {
        numbers(prefix + "0", k - 1);
        cout << endl;
        numbers(prefix + "1", k - 1);
    }
}

int main()
{
    
}