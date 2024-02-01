#include "function.h"
#include "Stack.h"
#include "BigInt.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846

void solve_variable(string arr[], int& size, int& start, int& point, double *reso) {
	string new_arr[1000];
	int j = 0;
	string save_name = "";
	for (int i = start+1; arr[i] != "," && i < size; ++i) {
		if (arr[i] == "=") {
			save_name = arr[i - 1];
		}
		new_arr[j] = arr[i];
		++j;
		start = i+1;
	}
	stack st(1000);
	string input = polish_natation(new_arr, j, st);
	stack second_stack(1000);
	string res = Math(input, second_stack);
	for (int i = start + 1; i < size; ++i) {
		if (arr[i] == save_name) {
			arr[i] = res;
		}
	}
	reso[point] = stod(res);
	++point;
}
int count_variable(string arr[], int& size, string* variable_arr) {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		if (type(arr[i]) == 10) {
			variable_arr[count] = arr[i];
			++count;
		}
	}
	return count;
}
void delete_spaces(string& input) {
	string new_string = "";
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] != ' ' && input[i] != '\n') {
			new_string += input[i];
		}
	}
	input = new_string;
}
bool check(string& input) {
	for (int i = 1; input[i] != '\0'; ++i) {

		if (input[i] == '*' && input[i - 1] == '*') {
			cout << "The expression is incorrect, write again:" << endl;
			return true;
		}
		if (input[i] == '/' && input[i - 1] == '/') {
			cout << "The expression is incorrect, write again:" << endl;
			return true;
		}
		if (input[i] == '*' && input[i - 1] == '/') {
			cout << "The expression is incorrect, write again:" << endl;
			return true;
		}
		if (input[i] == '/' && input[i - 1] == '*') {
			cout << "The expression is incorrect, write again:" << endl;
			return true;
		}
		if (input[i] == '+' && input[i - 1] == '+') {
			input[i - 1] = ' ';
		}
		if (input[i] == '-' && input[i - 1] == '-') {
			input[i - 1] = ' ';
			input[i] = '+';
		}
		if (input[i] == '+' && input[i - 1] == '-') {
			input[i - 1] = ' ';
			input[i] = '-';
		}
		if (input[i] == '-' && input[i - 1] == '+') {
			input[i - 1] = ' ';
			input[i] = '-';
		}
	}
	delete_spaces(input);
	return false;
}
void scan(string& input) {
	char arr[1000];
	fgets(arr, 1000, stdin);
	for (int i = 0; i < 1000; ++i) {
		input += arr[i];
	}
}
void string_to_array(string& input, string arr[], int& size) {
	string x = "";
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] == '(' && x != "" && type(x) == 10) {
			while (input[i] != '\0') {
				x += input[i];
				if (input[i] == ')') {
					break;
				}
				++i;
			}
			++i;
			arr[size] = x;
			++size;
			x = "";
		}
		if (x == "sin" || x == "cos" || x == "tg" || x == "ctg" || x == "arcsin" || x == "arccos" || x == "arctg" || x == "arcctg" || x == "log") {
			arr[size] = x;
			++size;
			x = "";
		}
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '!' || input[i] == '=' || input[i] == ',' || input[i] == '(' || input[i] == ')') {
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
		arr[size] = x;
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
	if (x == ",")
		return 8;
	if (x == "=")
		return 9;
	for (int i = 0; x[i] != '\0'; ++i) {
		if (x[i] == '0' || x[i] == '1' || x[i] == '2' || x[i] == '3' || x[i] == '4' || x[i] == '5' || x[i] == '6' || x[i] == '7' || x[i] == '8' || x[i] == '9') {
			return 0;
		}
	}
	return 10;
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

string Math(string& polish, stack& p_stack)
{
	string number;
	string operatr;
	double firstOperand, secondOperand;
	BigInt firstBigInt();
	BigInt secondBigInt();
	int flag_BigInt = 0;
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
				string pop1 = p_stack.pop();
				string pop2 = p_stack.pop();
				if (pop1.size() >= 10 || pop2.size() >= 10)
				{
					BigInt firstBigInt(pop1);
					BigInt secondBigInt(pop2);
					if (polish[i] == '+')
					{
						p_stack.push(secondBigInt.operator+(firstBigInt).to_str());
					}
					else if (polish[i] == '-')
					{
						p_stack.push(secondBigInt.operator-(firstBigInt).to_str());
					}
					else if (polish[i] == '*')
					{
						p_stack.push(secondBigInt.operator*(firstBigInt).to_str());
					}
					else if (polish[i] == '/')
					{
						p_stack.push(secondBigInt.operator/(firstBigInt).to_str());
					}
					
				}
				else
				{
					firstOperand = stod(pop1);
					secondOperand = stod(pop2);
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
			}
			else
			{
				break;
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
					p_stack.push(to_string(sin(a * M_PI / 180)));
				}
				else if (operatr == "cos")
				{
					p_stack.push(to_string(cos(a*M_PI/180)));
				}
				else if (operatr == "tg")
				{
					p_stack.push(to_string(tan(a * M_PI / 180)));
				}
				else if (operatr == "ctg")
				{
					p_stack.push(to_string(cos(a * M_PI / 180) / sin(a * M_PI / 180)));
				}
				else if (operatr == "arcsin")
				{
					p_stack.push(to_string(asin(a * M_PI / 180)));
				}
				else if (operatr == "arccos")
				{
					p_stack.push(to_string(acos(a * M_PI / 180)));
				}
				else if (operatr == "arctg")
				{
					p_stack.push(to_string(atan(a * M_PI / 180)));
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
	return p_stack.pop();
}
