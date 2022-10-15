#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#pragma once

#include <string>

using namespace std;

void addZero();
void negCondition();
string reverse();
void whichGreater();

class BigDecimalInt
{
private:
    string str;

public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    ~BigDecimalInt();
    string getstr();
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator> (BigDecimalInt anotherDec);
    BigDecimalInt operator< (BigDecimalInt anotherDec);
    
};

#endif

