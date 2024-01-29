#include "variable.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
void variable::set_name(string namee) {
	this->name = namee;
}
void variable::set_value(double valuee) {
	this->value = valuee;
}
void variable::set_value(int valuee) {
	this->value = valuee;
}