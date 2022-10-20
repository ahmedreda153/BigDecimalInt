#include <iostream>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main()
{
    BigDecimalInt c1("");
    BigDecimalInt c2("");
    BigDecimalInt c3 = c1 + c2;
    cout<<c3;
}