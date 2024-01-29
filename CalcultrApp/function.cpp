#include "function.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

void delete_spaces(string& input) {
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
		if (x == "sin" || x == "cos" || x == "tg" || x == "ctg" || x == "arcsin" || x == "arccos" || x == "arctg" || x == "arcctg" || x == "log") {
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

string polish_natation(string* arr, int& size, stack& st) {
	string ans = "";
	for (int i = 0; i < size; ++i) {
		if (type(arr[i]) == 7) {
			string y = st.pop();
			while (true) {
				if (y == "@@@") {
					break;
				}
				if (y == "^") {
					ans += "^ ";
				}
				if (y != "^") {
					st.push(y);
					break;
				}
				y = st.pop();
			}
			st.push(arr[i]);
		}
		else if (type(arr[i]) == 6) {
			ans += arr[i] + " ";
		}
		else if (type(arr[i]) == 4) {
			st.push(arr[i]);
		}
		else if (type(arr[i]) == 0) {
			ans += arr[i] + " ";
		}
		else if (type(arr[i]) == 2) {
			st.push(arr[i]);
		}
		else if (type(arr[i]) == 3) {
			string y = st.pop();
			while (true) {
				if (y == "@@@")
					break;
				if (y == "(") {
					string y = st.pop();
					if (type(y) == 4) {
						ans += y + " ";
					}
					else if (y != "@@@") {
						st.push(y);
					}
					else
						break;
					break;
				}
				ans += y + " ";
				y = st.pop();
			}
		}
		else if (type(arr[i]) == 1) {
			string y = st.pop();
			while (true) {
				if (y == "@@@")
					break;
				if (y == "(") {
					st.push(y);
					break;
				}
				ans += y + " ";
				y = st.pop();
			}
			st.push(arr[i]);
		}
		else if (type(arr[i]) == 5) {
			string y = st.pop();
			while (true) {
				if (y == "@@@")
					break;
				if (y == "(") {
					st.push(y);
					break;
				}
				if (y == "+" || y == "-") {
					st.push(y);
					break;
				}
				ans += y + " ";
				y = st.pop();
			}
			st.push(arr[i]);
		}
	}
	if (!st.isEmpty()) {
		string y = st.pop();
		while (true) {
			if (y == "@@@") {
				break;
			}
			ans += y + " ";
			y = st.pop();
		}
	}
	ans += '\0';
	return ans;
}

int type(string x) {
	if (x == "+" || x == "-")
		return 1;
	if (x == "(")
		return 2;
	if (x == ")")
		return 3;
	if (x == "sin" || x == "cos" || x == "tg" || x == "ctg" || x == "arcsin" || x == "arccos" || x == "arctg" || x == "arcctg" || x == "ln" || x == "sqrt")
		return 4;
	if (x == "/" || x == "*")
		return 5;
	if (x == "!")
		return 6;
	if (x == "^")
		return 7;
	return 0;
}

double BinaryPower(double b, unsigned long long e) {
	double v = 1.0;
	while (e != 0) {
		if ((e & 1) != 0) {
			v *= b;
		}
		b *= b;
		e >>= 1;
	}
	return v;
}

double Math(string& polish, stack& p_stack)
{
	string number;
	string operatr;
	double firstOperand, secondOperand;
	for (int i = 0; i < polish.size(); ++i)
	{
		if (polish[i] >= '0' && polish[i] <= '9' || polish[i] == '.')
		{
			number.push_back(polish[i]);
		}
		else if (polish[i] == '+' || polish[i] == '-' || polish[i] == '/' || polish[i] == '*' || polish[i] == '^')
		{
			if (number.size() > 0)
			{
				p_stack.push(number);
				number.clear();
			}
			
			if (p_stack.size() == 1 && polish[i] == '-')
			{
				double b = stod(p_stack.pop());
				p_stack.push(to_string(b * (-1)));
				continue;
			}
			if (p_stack.size() >= 2)
			{
				firstOperand = stod(p_stack.pop());
				secondOperand = stod(p_stack.pop());
			}
			else
			{
				break;
			}
			if (polish[i] == '+')
			{
				p_stack.push(to_string(firstOperand + secondOperand));
			}
			else if (polish[i] == '-')
			{
				p_stack.push(to_string(secondOperand - firstOperand));
			}
			else if (polish[i] == '*')
			{
				p_stack.push(to_string(secondOperand * firstOperand));
			}
			else if (polish[i] == '/')
			{
				p_stack.push(to_string(secondOperand / firstOperand));
			}
			else if (polish[i] == '^')
			{
				p_stack.push(to_string(pow(secondOperand, firstOperand)));
			}
			
		}
		else if (polish[i] == ' ' || polish[i] == '\0')
		{
			if (number.size() > 0)
			{
				p_stack.push(number);
				number.clear();
			}
			else if (operatr.size() > 0)
			{
				double a = stod(p_stack.pop());
				if (operatr == "sin")
				{
					p_stack.push(to_string(sin(a)));
				}
				else if (operatr == "cos")
				{
					p_stack.push(to_string(cos(a)));
				}
				else if (operatr == "tg")
				{
					p_stack.push(to_string(tan(a)));
				}
				else if (operatr == "ctg")
				{
					p_stack.push(to_string(cos(a) / sin(a)));
				}
				else if (operatr == "arcsin")
				{
					p_stack.push(to_string(asin(a)));
				}
				else if (operatr == "arccos")
				{
					p_stack.push(to_string(acos(a)));
				}
				else if (operatr == "ln")
				{
					p_stack.push(to_string(log(a)));
				}
				else if (operatr == "sqrt")
				{
					p_stack.push(to_string(sqrt(a)));
				}
			}
			operatr.clear();
		}
		else
		{
			operatr.push_back(polish[i]);
		}
	}
	return stod(p_stack.pop());
}