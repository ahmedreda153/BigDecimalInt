#include <iostream>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    BigDecimalInt c1(s1);
    cin >> s2;
    BigDecimalInt c2(s2);
    cout << c1 + c2;
}