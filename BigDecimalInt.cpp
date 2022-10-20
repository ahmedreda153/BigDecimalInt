// FCAI - OOP - 2022 - Assignment 1
// Program Name: BigDecimalInt
// Program Description: taking two complex number and do operation on them
// Last Modification Date: 19/10/2022
// First author  / ID : Ahmed Reda Elsayed / 20210018
// second author / ID : Ahmed Alaa Mohamed / 20210027
// Third author  / ID : Mohamed abdellatif abdelmoniem / 20200461
// Under The Supervision of: Dr. Mohamed El-Ramly

#include "BigDecimalInt.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

bool checkValidity(string s) // check input validity
{
	regex temp("[+-]?[0-9]+");
	return regex_match(s, temp);
}

BigDecimalInt::BigDecimalInt(string decStr)
{
	if (checkValidity(decStr))
	{
		str = decStr;
	}
	else
	{
		cout << "invalid input";
		exit(0);
	}
}

BigDecimalInt::BigDecimalInt(int decInt) : str(to_string(decInt))
{
}

BigDecimalInt::~BigDecimalInt()
{
}

string BigDecimalInt::getstr()
{
	return str;
}
/*Functions which will use in the code*/

void removeFrontzeroes(string &str1, string &str2) // to erase left zeroes from begin of string
{
	while (str1[0] == '0' || str2[0] == '0')
	{
		if (str1[0] == '0')
		{
			str1.erase(0, 1);
		}
		if (str2[0] == '0')
		{
			str2.erase(0, 1);
		}
	}
}

void addZero(int &sizeDiff, string &temp, string &str) // to add zeroes from begin to equal sizes
{
	for (int i = 0; i < sizeDiff; i++)
	{
		temp += '0';
	}
	str = temp + str;
}

void negCondition(int &carry, bool &negSign1, bool &sign, bool &carryCheck, string &tempChar2, string &tempChar1, string &answer) // negative condition if there's negative input
{
	if (negSign1)
	{
		sign = false;
	}
	else
	{
		sign = true;
	}
	if (stoi(tempChar2) - stoi(tempChar1) - carry >= 0)
	{
		answer += to_string(stoi(tempChar2) - stoi(tempChar1) - carry);
		carryCheck = true;
	}
	else
	{
		carryCheck = false;
		answer += to_string((stoi(tempChar2) + 10) - stoi(tempChar1) - carry);
		carry = 1;
	}
}

string reverse(string str1, string str2) // to reverse answer before return output
{
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		str2 += str1[i];
	}
	return str2;
}

void subtract(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2) // substraction algorithm
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (carryCheck)
		{
			carry = 0;
		}
		tempChar1 = str[i];
		tempChar2 = str2[i];
		if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
		{
			answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
			carryCheck = true;
		}
		else
		{
			carryCheck = false;
			answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
			carry = 1;
		}
	}
}

void sum(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2) // sum algorithm
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (carryCheck)
		{
			carry = 0;
		}
		tempChar1 = str[i];
		tempChar2 = str2[i];
		if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
		{
			answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
			carryCheck = true;
		}
		else
		{
			carryCheck = false;
			if (i == 0)
			{
				answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
				answer += '1';
			}
			else
			{
				answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
				carry = 1;
			}
		}
	}
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
	int sizeDiff, carry = 0, firstStringSize, secondStringSize, removeZero = 0;
	string temp = "", answer = "", tempChar1, tempChar2;
	bool carryCheck = true, negSign1 = false, negSign2 = false, sign = false, whichOne = true;

	if (str[0] == '+')
	{
		str.erase(0, 1);
	}

	if (anotherDec.str[0] == '+')
	{
		anotherDec.str.erase(0, 1);
	}

	if (str[0] == '-' && anotherDec.str[0] == '-')
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		sign = true; // the result  will be negative
	}

	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		str.erase(0, 1);
		whichOne = false; // negative codition
		negSign1 = true;
	}

	else if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		anotherDec.str.erase(0, 1);
		whichOne = false;
		negSign2 = true;
	}
	removeFrontzeroes(str, anotherDec.str);
	sizeDiff = max(str.length(), anotherDec.str.length()) - min(str.length(), anotherDec.str.length());
	firstStringSize = str.length();
	secondStringSize = anotherDec.str.length();
	if (str.length() < anotherDec.str.length())
	{
		addZero(sizeDiff, temp, str);
	}
	else
	{
		addZero(sizeDiff, temp, anotherDec.str);
	}
	if (whichOne == false && firstStringSize == secondStringSize) // if the size equal each other check which input is greater
	{
		for (int i = 0; i < str.length(); i++)
		{
			tempChar1 = str[i];
			tempChar2 = anotherDec.str[i];
			if (stoi(tempChar1) > stoi(tempChar2))
			{
				firstStringSize++;
				removeZero = i;
				break;
			}
			else if (stoi(tempChar1) < stoi(tempChar2))
			{
				secondStringSize++;
				removeZero = i;
				break;
			}
			else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
			{
				answer = '0';
				removeZero = str.length();
			}
		}
	}
	if (whichOne)
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (carryCheck)
			{
				carry = 0;
			}
			tempChar1 = str[i];
			tempChar2 = anotherDec.str[i];
			if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
			{
				answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
				carryCheck = true;
			}
			else
			{
				carryCheck = false;
				if (i == 0)
				{
					answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
					answer += '1'; // if the sum of the first digit in the two input has carry print "1" in the left
				}
				else
				{
					answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
					carry = 1;
				}
			}
		}
	}
	else
	{
		for (int i = str.length() - 1; i >= 0 + removeZero; i--)
		{
			if (carryCheck)
			{
				carry = 0;
			}
			tempChar1 = str[i];
			tempChar2 = anotherDec.str[i];
			if (firstStringSize < secondStringSize)
			{
				negCondition(carry, negSign1, sign, carryCheck, tempChar2, tempChar1, answer);
			}
			else if (secondStringSize < firstStringSize)
			{
				negCondition(carry, negSign2, sign, carryCheck, tempChar1, tempChar2, answer);
			}
		}
	}
	if (sign)
	{
		answer += '-';
	}
	return BigDecimalInt(reverse(answer, ""));
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{

	int sizeDiff, carry = 0, firstStringSize, secondStringSize, zeros{0};
	string temp = "", answer = "", tempChar1, tempChar2, tempChar3, tempChar4;
	bool carryCheck = true, negSign1 = false, negSign2 = false, sign = false, whichOne = true, check = false;
	firstStringSize = str.length();
	secondStringSize = anotherDec.str.length();
	sizeDiff = max(str.length(), anotherDec.str.length()) - min(str.length(), anotherDec.str.length());

	/*removing + sign from inputs because it's positive anyway*/
	if (str[0] == '+')
	{
		str.erase(0, 1);
	}
	if (anotherDec.str[0] == '+')
	{
		anotherDec.str.erase(0, 1);
	}

	// divide substraction to 4 parts
	if (str[0] != '-' && anotherDec.str[0] != '-') // part 1 if the two input is positive
	{
		removeFrontzeroes(str, anotherDec.str);
		if (str.length() == anotherDec.str.length())
		{
			for (size_t i = 0; i < str.length(); i++)
			{
				if (str[i] != anotherDec.str[i])
				{
					tempChar3 = str[i];
					tempChar4 = anotherDec.str[i];
					break;
				}
				if (i == str.length() - 1 && str[i] == anotherDec.str[i]) // add zeroes to make the length equal
				{
					answer += '0';
					return BigDecimalInt(answer);
				}
			}

			if (stoi(tempChar3) < stoi(tempChar4))
			{
				str.swap(anotherDec.str);
			}
			subtract(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			// to remove zeros which will appear in the left in the result
			int i = 1;
			while (answer[str.length() - i] == '0')
			{
				answer.pop_back();
				i++;
			}

			if (stoi(tempChar3) < stoi(tempChar4)) // to assign sign to the answer
			{
				answer += '-';
			}

			return BigDecimalInt(reverse(answer, ""));
		}
		else
		{

			if (secondStringSize > firstStringSize)
			{
				anotherDec.str.swap(str);

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				anotherDec.str = temp + anotherDec.str;
				sign = true;
			}
			if (secondStringSize < firstStringSize)
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				anotherDec.str = temp + anotherDec.str;
			}
			subtract(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);
			if (sign)
			{
				answer += '-';
			}
			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] != '-' && anotherDec.str[0] == '-') // part 2
	{
		anotherDec.str.erase(0, 1);
		removeFrontzeroes(str, anotherDec.str);
		if (str.length() == anotherDec.str.length())
		{
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			return BigDecimalInt(reverse(answer, ""));
		}

		else
		{

			if (anotherDec.str.length() > str.length())
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				str = temp + str;
			}
			else if (anotherDec.str.length() < str.length())
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				anotherDec.str = temp + anotherDec.str;
			}
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] == '-' && anotherDec.str[0] != '-') // part 3
	{
		str.erase(0, 1);
		removeFrontzeroes(str, anotherDec.str);
		if (str.length() == anotherDec.str.length())
		{
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);
			answer += '-';
			return BigDecimalInt(reverse(answer, ""));
		}
		else
		{

			if (anotherDec.str.length() > str.length())
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				str = temp + str;
			}
			else if (anotherDec.str.length() < str.length())
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				anotherDec.str = temp + anotherDec.str;
			}
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			answer += '-';
			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] == '-' && anotherDec.str[0] == '-') // part 4
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		removeFrontzeroes(str, anotherDec.str);
		tempChar3 = str[0];
		tempChar4 = anotherDec.str[0];
		if (str.length() == anotherDec.str.length())
		{
			if (stoi(tempChar3) < stoi(tempChar4))
			{
				str.swap(anotherDec.str);
			}
			subtract(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			if (stoi(tempChar3) > stoi(tempChar4))
			{
				answer += '-';
			}
			return BigDecimalInt(reverse(answer, ""));
		}
		else
		{
			if (anotherDec.str.length() > str.length())
			{
				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				str = temp + str;
				str.swap(anotherDec.str);
			}
			else if (anotherDec.str.length() < str.length())
			{

				for (int i = 0; i < sizeDiff; i++)
				{
					temp += '0';
				}
				anotherDec.str = temp + anotherDec.str;
				sign = true;
			}
			subtract(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);

			if (sign)
			{
				answer += '-';
			}
			return BigDecimalInt(reverse(answer, ""));
		}
	}
}

bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
	string tempChar1, tempChar2;

	if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		return true;
	}
	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		return false;
	}
	else if (str[0] == '-' && anotherDec.str[0] == '-')
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		if (str.length() == anotherDec.str.length()) // check which greater if the size of inputs is equal
		{
			for (int i = 0; i < str.length(); i++)
			{
				tempChar1 = str[i];
				tempChar2 = anotherDec.str[i];
				if (stoi(tempChar1) < stoi(tempChar2))
				{
					return true;
					break;
				}
				else if (stoi(tempChar1) > stoi(tempChar2))
				{
					return false;
					break;
				}
				else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
				{
					return false;
				}
			}
		}
		else
		{
			if (str.length() < anotherDec.str.length())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (str[0] != '-' && anotherDec.str[0] != '-')
	{
		if (str[0] == '+')
		{
			str.erase(0, 1);
		}
		if (anotherDec.str[0] == '+')
		{
			anotherDec.str.erase(0, 1);
		}
		if (str.length() == anotherDec.str.length())
		{
			for (int i = 0; i < str.length(); i++)
			{
				tempChar1 = str[i];
				tempChar2 = anotherDec.str[i];
				if (stoi(tempChar1) < stoi(tempChar2))
				{
					return false;
					break;
				}
				else if (stoi(tempChar1) > stoi(tempChar2))
				{
					return true;
					break;
				}
				else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
				{
					return false;
				}
			}
		}
		else
		{
			if (str.length() > anotherDec.str.length())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{
	string tempChar1, tempChar2;

	if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		return true;
	}
	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		return false;
	}
	else if (str[0] == '-' && anotherDec.str[0] == '-')
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		if (str.length() == anotherDec.str.length())
		{

			for (int i = 0; i < str.length(); i++)
			{
				tempChar1 = str[i];
				tempChar2 = anotherDec.str[i];
				if (stoi(tempChar1) < stoi(tempChar2))
				{
					return false;
					break;
				}
				else if (stoi(tempChar1) > stoi(tempChar2))
				{
					return true;
					break;
				}
				else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
				{
					return false;
				}
			}
		}
		else
		{
			if (str.length() < anotherDec.str.length())
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else if (str[0] != '-' && anotherDec.str[0] != '-')
	{
		if (str[0] == '+')
		{
			str.erase(0, 1);
		}
		if (anotherDec.str[0] == '+')
		{
			anotherDec.str.erase(0, 1);
		}
		if (str.length() == anotherDec.str.length())
		{
			for (int i = 0; i < str.length(); i++)
			{
				tempChar1 = str[i];
				tempChar2 = anotherDec.str[i];
				if (stoi(tempChar1) < stoi(tempChar2))
				{
					return true;
					break;
				}
				else if (stoi(tempChar1) > stoi(tempChar2))
				{
					return false;
					break;
				}
				else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
				{
					return false;
				}
			}
		}
		else
		{
			if (str.length() > anotherDec.str.length())
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{
	string x = str;
	string y = anotherDec.getstr();
	if (x.size() != anotherDec.getstr().size())
	{
		return false;
	}
	for (long long i = x.size() - 1; i >= 0; i--)
	{
		if (x[i] != y[i])
		{
			return false;
		}
	}
	return true;
}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
	string y = anotherDec.getstr();
	str = y;
	return BigDecimalInt(str);
}

int BigDecimalInt::Size()
{
	if (str[0] == '+')
	{
		return (str.size() - 1);
	}
	else if (str[0] == '-')
	{
		return (str.size() - 1);
	}
	else
	{
		return str.size();
	}
}

char BigDecimalInt::sign()
{
	char temp;
	if (str[0] == '-')
	{
		temp = '-';
		cout << "The sign is : ";
		return temp;
	}
	else
	{
		temp = '+';
		cout << "The sign is : ";
		return temp;
	}
}

ostream &operator<<(ostream &out, BigDecimalInt b)
{
	out << b.getstr() << endl;
	return out;
}