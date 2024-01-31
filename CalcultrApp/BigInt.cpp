#include "BigInt.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

BigInt::BigInt(string& s)
{
	if (s[0] == '-')
	{
		this->sign = 1;
		for (int i = 1; i < s.length(); ++i)
		{
			this->number.push_back(s[i] - '0');
		}
	}
	else
	{
		this->sign = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			this->number.push_back(s[i] - '0');
		}
	}
	reverse(this->number.begin(), this->number.end());
}

BigInt::BigInt(vector<int> numb)
{
	this->number = numb;
	this->sign = 0;
}

void BigInt::write() const
{
	if (this->sign == 1)
	{
		cout << '-';
	}
	for (int i = this->number.size()-1; i >= 0; --i)
	{
		cout << this->number[i];
	}
}

BigInt BigInt::pluss(BigInt& a)
{
	int carry = 0;
	vector <int> res;
	for (int i = 0; i < min(a.number.size(), this->number.size()); ++i)
	{
		int cur_sum = a.number[i] + this->number[i] + carry;
		res.push_back(cur_sum % 10);
		carry = cur_sum / 10;
	}
	for (int i = min(a.number.size(), this->number.size()); i < max(a.number.size(), this->number.size()); ++i)
	{
		if (a.number.size() > this->number.size())
		{
			int cur_sum = a.number[i] + carry;
			res.push_back(cur_sum % 10);
			carry = cur_sum / 10;
		}
		else
		{
			int cur_sum = this->number[i] + carry;
			res.push_back(cur_sum % 10);
			carry = cur_sum / 10;
		}
	}
	if (carry != 0)
	{
		res.push_back(carry);
	}
	BigInt c(res);
	return c;
}

BigInt BigInt::minuss(BigInt& a)
{
	vector <int> res;
	int car = 0;
	for (int i = 0; i < a.number.size(); ++i)
	{
		int diff = this->number[i] - a.number[i] - car;
		if (diff < 0)
		{
			diff += 10;
			car = 1;
		}
		else
		{
			car = 0;
		}
		res.push_back(diff);
	}
	for (int i = a.number.size(); i < this->number.size(); ++i)
	{
		if (this->number[i] - car < 0)
		{
			res.push_back(this->number[i] + 10 - car);
			car = 1;
		}
		else
		{
			res.push_back(this->number[i] - car);
			car = 0;
		}
		
	}
	BigInt c(res);
	return c;
}

bool BigInt::operator >(BigInt& a)
{
	if (this->number.size() > a.number.size())
		return true;
	else if (this->number.size() < a.number.size())
		return false;
	else
	{
		for (int i = this->number.size() - 1; i >= 0; --i)
		{
			if (this->number[i] > a.number[i])
				return true;
			else if (this->number[i] < a.number[i])
			{
				return false;
			}
		}
	}
}

bool BigInt::operator = (BigInt& a)
{
	if (this->number.size() != a.number.size())
	{
		return false;
	}
	else
	{
		for (int i = this->number.size() - 1; i >= 0; --i)
		{
			if (this->number[i] != a.number[i])
				return false;
		}
	}
	return true;
}

void BigInt::setSign(int sign)
{
	this->sign = sign;
}

BigInt BigInt::operator+(BigInt& a)
{
	if (a.sign == 0 && this->sign == 0)
	{
		BigInt c = this->pluss(a);
		return c;
	}
	else if (a.sign == 1 && this->sign == 0)
	{
		if (this->operator>(a) || this->operator=(a))
		{
			BigInt c = this->minuss(a);
			return c;
		}
		else
		{
			BigInt c = a.minuss(*this);
			c.setSign(1);
			return c;
		}
	}
	else if (a.sign == 0 && this->sign == 1)
	{
		if (a.operator>(*this) || a.operator=(*this))
		{
			BigInt c = a.minuss(*this);
			return c;
		}
		else
		{
			BigInt c = this->minuss(a);
			c.setSign(1);
			return c;
		}
	}
	else
	{
		BigInt c = this->pluss(a);
		c.setSign(1);
		return c;
	}
}

BigInt BigInt::operator-(BigInt& a)
{
	
}