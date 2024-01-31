#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt
{
public:
	BigInt()
	{
		number.push_back(0);
		sign = 0;
	}
	BigInt(string& s);
	BigInt(vector<int> numb);
	void write() const;
	BigInt pluss(BigInt& a);
	BigInt minuss(BigInt& a);
	bool operator > (BigInt& a);
	bool operator = (BigInt& a);
	void setSign(int sign);
	BigInt operator + (BigInt& a);
	BigInt operator - (BigInt& a);
private:
	vector<int> number;
	int sign;
};