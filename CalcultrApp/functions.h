#pragma once
#include <string>
#include <iostream>
using namespace std;

void delete_spaces(string& input);
void scan(string& input);
void string_to_array(string& input, string arr[], int& size);
string polish_natation(string* arr, int& size, stack& st);
int type(string x);

void delete_spaces(string &input) {
	string new_string = "";
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] != ' ' && input[i] != '\n') {
			new_string += input[i];
		}
	}
	input = new_string;
}
void scan(string& input) {
	char c;
	cin >> c;
	while (c != '=') {
		input += c;
		cin >> c;
	}
}
void string_to_array(string& input, string arr[], int& size) {
	string x = "";
	for (int i = 0; input[i] != '\0'; ++i) {
		if (x == "sin" || x == "cos" || x == "tg" || x == "ctg" || x == "arcsin" || x == "arccos" || x == "arctg" || x == "arcctg") {
			arr[size] = x;
			++size;
			x = "";
		}
		if (input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '!') {
			if (x != "") {
				arr[size] = x;
				++size;
			}
			arr[size] = input[i];
			++size;
			x = "";
		}
		
		else {
			x += input[i];
		}
	}
	if (x != "") {
		arr[size] += x;
		++size;
	}
}

string polish_natation(string*arr, int& size, stack& st) {
	string ans = "";
	for (int i = 0; i < size; ++i) {
		if (type(arr[i]) == 0) {
			ans += arr[i] + " ";
		}
		else if (type(arr[i]) == 1) {

		}
	}
	return ans;
}
int type(string x) {
	if (x == "+" || x == "-" || x == "/" || x == "*" || x == "!" || x == "^")
		return 1;
	if (x == "(")
		return 2;
	if (x == ")")
		return 3;
	if (x == "sin" || x == "cos" || x == "tg" || x == "ctg" || x == "arcsin" || x == "arccos" || x == "arctg" || x == "arcctg")
		return 4;
	return 0;
}