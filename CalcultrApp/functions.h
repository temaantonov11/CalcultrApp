#pragma once
#include <string>
#include <iostream>
using namespace std;

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
		if (input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
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
}
