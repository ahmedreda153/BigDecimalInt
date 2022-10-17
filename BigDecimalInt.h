#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#pragma once

#include <string>

using namespace std;

void removeFrontzeroes(string &str1, string &str2);
void addZero(int &sizeDiff, string &temp, string &str);
void negCondition(int &carry, bool &negSign1, bool &sign, bool &carryCheck, string &tempChar2, string &tempChar1, string &answer);
string reverse();
string reverse(string str1, string str2);
void whichGreater(string &tempChar1, string &tempChar2, string &answer, string &str1, string &str2);
void subtract(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2);
void sum(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2);


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

