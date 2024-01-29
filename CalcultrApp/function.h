#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;

void delete_spaces(string& input);
void scan(string& input);
void string_to_array(string& input, string arr[], int& size);
string polish_natation(string* arr, int& size, stack& st);
int type(string x);
double BinaryPower(double b, unsigned long long e);
double Math(string& polish, stack& p_stack);
bool check(string& input);

