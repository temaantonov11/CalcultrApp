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
string Math(string& polish, stack& p_stack);
bool check(string& input);
int count_variable(string arr[], int& size, string* variable_arr);
void solve_variable(string arr[], int& size, int& start, int& point, double* reso);
