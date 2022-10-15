#include <iostream>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main()
{
    BigDecimalInt c1("750");
    BigDecimalInt c2("-75");
    BigDecimalInt c3 = c1 + c2;
    // BigDecimalInt c3 = c1 < c2;
    cout << c3.getstr();
}