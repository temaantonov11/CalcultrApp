#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "doubleStack.h"
using namespace std;

enum {maxSize = 100};

float math(string& polish)
{
	doubleStack stack(maxSize);
	string number;
	float a = 0;
	float b = 0;
	float c = 0;
	for (int i = 0; i < polish.size(); ++i)
	{
		if (polish[i] >= '0' && polish[i] <= '9')
		{
			number.push_back(polish[i]);
		}
		else if (polish[i] == 'x')
		{
			if (number.size() != 0)
			{
				a = stof(number);
				stack.push(a);
				number.clear();
			}

			/* блок обработки переменной x */

		}
		else
		{
			if (number.size() != 0)
			{
				a = stof(number);
				stack.push(a);
				number.clear();
			}
			if (polish[i] == '-' || polish[i] == '+' || polish[i] == '*' || polish[i] == '/' || polish[i] == '^')
			{
				if (polish[i] == '-' && stack.size() == 1)
				{
					b = stack.view_top();
					stack.pop();
					stack.push(b * (-1));
				}
				else
				{
					b = stack.view_top();
					stack.pop();
					c = stack.view_top();
					stack.pop();
					if (polish[i] == '+')
					{
						stack.push(b + c);
					}
					else if (polish[i] == '-')
					{
						stack.push(c - b);
					}
					else if (polish[i] == '*')
					{
						stack.push(c * b);
					}
					else if (polish[i] == '/')
					{
						stack.push(c / b);
					}
					else if (polish[i] == '^')
					{
						stack.push(pow(c, b));
					}
				}
				
			}
			else
			{
				b = stack.view_top();
				stack.pop();
				if (polish[i] == 's') // sin
				{
					stack.push(sin(b));
				}
				else if (polish[i] == 'c') // cos
				{
					stack.push(cos(b));
				}
				else if (polish[i] == 't') // tg
				{
					stack.push(sin(b) / cos(b));
				}
				else if (polish[i] == 'k') // ctg
				{
					stack.push(cos(b) / sin(b));
				}
				else if (polish[i] == 'q') //sqrt
				{
					stack.push(sqrt(b));
				}
			}

		}
	}
	return stack.view_top();
}

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


