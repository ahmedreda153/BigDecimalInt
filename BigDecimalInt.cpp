#include "BigDecimalInt.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

BigDecimalInt::BigDecimalInt(string decStr) : str(decStr)
{
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

void removeFrontzeroes(string &str1, string &str2)
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

void addZero(int &sizeDiff, string &temp, string &str)
{
	for (int i = 0; i < sizeDiff; i++)
	{
		temp += '0';
	}
	str = temp + str;
}

void negCondition(int &carry, bool &negSign1, bool &sign, bool &carryCheck, string &tempChar2, string &tempChar1, string &answer)
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

string reverse(string str1, string str2)
{
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		str2 += str1[i];
	}
	return str2;
}

void whichGreater(string &tempChar1, string &tempChar2, string &answer, string &str1, string &str2)
{
	for (int i = 0; i < str1.length(); i++)
	{
		tempChar1 = str1[i];
		tempChar2 = str2[i];
		if (stoi(tempChar1) < stoi(tempChar2))
		{
			answer = "true";
			break;
		}
		else if (stoi(tempChar1) > stoi(tempChar2))
		{
			answer = "false";
			break;
		}
		else if (i == str1.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
		{
			answer = "false";
		}
	}
}

void subtract(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2)
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
void sum(string &str, string &tempChar1, string &tempChar2, string &answer, int &carry, bool &carryCheck, string &str2)
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
		sign = true;
	}
	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		str.erase(0, 1);
		whichOne = false;
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
		// for (int i = 0; i < sizeDiff; i++)
		// {
		// 	temp += '0';
		// }
		// str = temp + str;
	}
	else
	{
		addZero(sizeDiff, temp, anotherDec.str);
		// for (int i = 0; i < sizeDiff; i++)
		// {
		// 	temp += '0';
		// }
		// anotherDec.str = temp + anotherDec.str;
	}
	if (whichOne == false && firstStringSize == secondStringSize)
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
				// if (negSign1)
				// {
				// 	sign = false;
				// }
				// else
				// {
				// 	sign = true;
				// }
				// if (stoi(tempChar2) - stoi(tempChar1) - carry >= 0)
				// {
				// 	answer += to_string(stoi(tempChar2) - stoi(tempChar1) - carry);
				// 	carryCheck = true;
				// }
				// else
				// {
				// 	carryCheck = false;
				// 	answer += to_string((stoi(tempChar2) + 10) - stoi(tempChar1) - carry);
				// 	carry = 1;
				// }
			}
			else if (secondStringSize < firstStringSize)
			{
				negCondition(carry, negSign2, sign, carryCheck, tempChar1, tempChar2, answer);
				// if (negSign2)
				// {
				// 	sign = false;
				// }
				// else
				// {
				// 	sign = true;
				// }
				// if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
				// {
				// 	answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
				// 	carryCheck = true;
				// }
				// else
				// {
				// 	carryCheck = false;
				// 	answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
				// 	carry = 1;
				// }
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

	if (str[0] == '+')
	{
		str.erase(0, 1);
	}
	if (anotherDec.str[0] == '+')
	{
		anotherDec.str.erase(0, 1);
	}

	if (str[0] != '-' && anotherDec.str[0] != '-')
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
				if (i == str.length() - 1 && str[i] == anotherDec.str[i])
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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
			// 	{
			// 		answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
			// 		carry = 1;
			// 	}
			// }

			int i = 1;
			while (answer[str.length() - i] == '0')
			{
				answer.pop_back();
				i++;
			}

			if (stoi(tempChar3) < stoi(tempChar4))
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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
			// 	{
			// 		answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
			// 		carry = 1;
			// 	}
			// }

			if (sign)
			{
				answer += '-';
			}
			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		anotherDec.str.erase(0, 1);
		removeFrontzeroes(str, anotherDec.str);
		if (str.length() == anotherDec.str.length())
		{
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
			// 	{
			// 		answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		if (i == 0)
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			answer += '1';
			// 		}
			// 		else
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			carry = 1;
			// 		}
			// 	}
			// }

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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
			// 	{
			// 		answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
			// 		carryCheck = true;
			// 	}

			// 	else
			// 	{
			// 		carryCheck = false;
			// 		if (i == 0)
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			answer += '1';
			// 		}
			// 		else
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			carry = 1;
			// 		}
			// 	}
			// }

			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		str.erase(0, 1);
        removeFrontzeroes(str, anotherDec.str);
		if (str.length() == anotherDec.str.length())
		{
			sum(str, tempChar1, tempChar2, answer, carry, carryCheck, anotherDec.str);
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
			// 	{
			// 		answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		if (i == 0)
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			answer += '1';
			// 		}
			// 		else
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			carry = 1;
			// 		}
			// 	}
			// }

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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) + stoi(tempChar2) + carry < 10)
			// 	{
			// 		answer += to_string(stoi(tempChar1) + stoi(tempChar2) + carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		if (i == 0)
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			answer += '1';
			// 		}
			// 		else
			// 		{
			// 			answer += to_string((stoi(tempChar1) + stoi(tempChar2) + carry) - 10);
			// 			carry = 1;
			// 		}
			// 	}
			// }

			answer += '-';
			return BigDecimalInt(reverse(answer, ""));
		}
	}

	else if (str[0] == '-' && anotherDec.str[0] == '-')
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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
			// 	{
			// 		answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
			// 		carry = 1;
			// 	}
			// }
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
			// for (int i = str.length() - 1; i >= 0; i--)
			// {
			// 	if (carryCheck)
			// 	{
			// 		carry = 0;
			// 	}
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) - stoi(tempChar2) - carry >= 0)
			// 	{
			// 		answer += to_string(stoi(tempChar1) - stoi(tempChar2) - carry);
			// 		carryCheck = true;
			// 	}
			// 	else
			// 	{
			// 		carryCheck = false;
			// 		answer += to_string((stoi(tempChar1) + 10) - stoi(tempChar2) - carry);
			// 		carry = 1;
			// 	}
			// }

			if (sign)
			{
				answer += '-';
			}
			return BigDecimalInt(reverse(answer, ""));
		}
	}
}

BigDecimalInt BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
	string answer = "", tempChar1, tempChar2;

	if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		answer = "true";
	}
	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		answer = "false";
	}
	else if (str[0] == '-' && anotherDec.str[0] == '-')
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		if (str.length() == anotherDec.str.length())
		{
			whichGreater(tempChar1, tempChar2, answer, str, anotherDec.str);
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) < stoi(tempChar2))
			// 	{
			// 		answer = "true";
			// 		break;
			// 	}
			// 	else if (stoi(tempChar1) > stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 		break;
			// 	}
			// 	else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 	}
			// }
		}
		else
		{
			if (str.length() < anotherDec.str.length())
			{
				answer = "true";
			}
			else
			{
				answer = "false";
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
			whichGreater(tempChar2, tempChar1, answer, anotherDec.str, str);
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar2) < stoi(tempChar1))
			// 	{
			// 		answer = "true";
			// 		break;
			// 	}
			// 	else if (stoi(tempChar2) > stoi(tempChar1))
			// 	{
			// 		answer = "false";
			// 		break;
			// 	}
			// 	else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 	}
			// }

			// tempChar3 = str[0];
			// tempChar4 = anotherDec.str[0];
			// if (stoi(tempChar3) > stoi(tempChar4))
			// {
			// 	answer = "true";
			// }
			// else
			// {
			// 	answer = "false";
			// }
		}
		else
		{
			if (str.length() > anotherDec.str.length())
			{
				answer = "true";
			}
			else
			{
				answer = "false";
			}
		}
	}
	return BigDecimalInt(answer);
}

BigDecimalInt BigDecimalInt::operator<(BigDecimalInt anotherDec)
{
	string answer = "", tempChar1, tempChar2;
	// str.swap(anotherDec.str);

	if (str[0] != '-' && anotherDec.str[0] == '-')
	{
		answer = "true";
	}
	else if (str[0] == '-' && anotherDec.str[0] != '-')
	{
		answer = "false";
	}
	else if (str[0] == '-' && anotherDec.str[0] == '-')
	{
		str.erase(0, 1);
		anotherDec.str.erase(0, 1);
		if (str.length() == anotherDec.str.length())
		{
			whichGreater(tempChar1, tempChar2, answer, str, anotherDec.str);
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) < stoi(tempChar2))
			// 	{
			// 		answer = "true";
			// 		break;
			// 	}
			// 	else if (stoi(tempChar1) > stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 		break;
			// 	}
			// 	else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 	}
			// }
		}
		else
		{
			if (str.length() < anotherDec.str.length())
			{
				answer = "true";
			}
			else
			{
				answer = "false";
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
			whichGreater(tempChar1, tempChar2, answer, str, anotherDec.str);
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	tempChar1 = str[i];
			// 	tempChar2 = anotherDec.str[i];
			// 	if (stoi(tempChar1) < stoi(tempChar2))
			// 	{
			// 		answer = "true";
			// 		break;
			// 	}
			// 	else if (stoi(tempChar1) > stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 		break;
			// 	}
			// 	else if (i == str.length() - 1 && stoi(tempChar1) == stoi(tempChar2))
			// 	{
			// 		answer = "false";
			// 	}
			// }

			// tempChar3 = str[0];
			// tempChar4 = anotherDec.str[0];
			// if (stoi(tempChar3) > stoi(tempChar4))
			// {
			// 	answer = "true";
			// }
			// else
			// {
			// 	answer = "false";
			// }
		}
		else
		{
			if (str.length() > anotherDec.str.length())
			{
				answer = "true";
			}
			else
			{
				answer = "false";
			}
		}
	}
	return BigDecimalInt(answer);
}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{
	string x = this->getstr();
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

// BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
// {
//     string y = anotherDec.setstr();
//     // this->setstr(y);
//     return anotherDec;
// }

int BigDecimalInt::Size()
{
	return this->getstr().size();
}

// friend ostream &operator<<(ostream &out, BigDecimalInt b)
// {
//     out << b.getstr() << endl;
//     return out;
// }