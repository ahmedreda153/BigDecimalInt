// FCAI - OOP - 2022 - Assignment 1
// Program Name: BigDecimalInt
// Program Description: taking two complex number and do operation on them
// Last Modification Date: 19/10/2022
// First author  / ID : Ahmed Reda Elsayed / 20210018
// second author / ID : Ahmed Alaa Mohamed / 20210027
// Third author  / ID : Mohamed abdellatif abdelmoniem / 20200461
// Under The Supervision of: Dr. Mohamed El-Ramly

#include <iostream>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main()
{
    BigDecimalInt c1("");
    BigDecimalInt c2("");
    BigDecimalInt c3;
    BigDecimalInt ans;

    ans = c1 + c2; // First Test (+ operator)
    cout << ans.getstr() << endl;
    ans = c1 - c2; // Second Test (- operator)
    cout << ans.getstr() << endl;
    c3 = c2; // Third Test (= operator)
    ans = c1 + c3; // Fourth Test (+ operator)
    cout << ans << endl; // Fifth Test (<< operator)
    cout << (c1 > c2) << endl; // Sixth Test ( > operator)
    cout << (c1 < c2) << endl;   // Seventh Test ( < operator)
    cout << (c1 == c2) << endl;  // Eighth Test ( == operator)
    cout << c1.Size() << endl; // Ninth Test (Size() function)
    cout << c1.sign() << endl; // Tenth Test (sign() function)
}