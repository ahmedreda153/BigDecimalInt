#include <iostream>

using namespace std;

void Binary(int n)
{
    if (n == 0)
        return;
    Binary(n / 2);
    cout << n % 2;
}

int main()
{
    Binary(11);
}