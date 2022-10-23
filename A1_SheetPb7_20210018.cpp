#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

bool bears(int n)
{
    if (n < 42)
        return false;

    if (n == 42)
        return true;

    if ((n % 5 == 0) && bears(n - 42))
        return true;

    if ((n % 2 == 0) && bears(n / 2))
        return true;

    if (n % 4 == 0 || n % 3 == 0)
    {
        return (n % 10) * ((n % 100) / 10) != 0 && bears(n - (n % 10) * ((n % 100) / 10));
    }
    return false;
}

int main()
{
}