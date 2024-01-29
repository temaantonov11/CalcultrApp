#pragma once
#include <string>
using namespace std;
class variable {
public:
	variable() : name(""), value(0) {}
	void set_name(string namee);
	void set_value(double valuee);
	void set_value(int valuee);
private:
	string name;
	double value;
};