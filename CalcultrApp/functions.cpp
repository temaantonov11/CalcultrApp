#include "functions.h"
#include "doubleStack.h"
#include <string>
#include <cmath>

enum { maxSize = 100 };

double Math(string& polish, doubleStack& stack)
{
	string number;
	double pushNumb = 0;
	double firstOperand = 0;
	double secondOperand = 0;
	for (int i = 0; i < polish.size(); ++i)
	{
		if ((polish[i] >= '0' && polish[i] <= '9') || polish[i] == '.')
		{
			number.push_back(polish[i]);
		}
		else if (polish[i] == 'x')
		{
			if (number.size() != 0)
			{
				pushNumb = stod(number);
				stack.push(pushNumb);
				number.clear();
			}

			/* блок обработки переменной x */

		}
		else
		{
			if (number.size() != 0)
			{
				pushNumb = stod(number);
				stack.push(pushNumb);
				number.clear();
			}
			if (polish[i] == '-' || polish[i] == '+' || polish[i] == '*' || polish[i] == '/' || polish[i] == '^')
			{
				if (polish[i] == '-' && stack.size() == 1)
				{
					firstOperand = stack.view_top();
					stack.pop();
					stack.push(firstOperand * (-1));
				}
				else
				{
					firstOperand = stack.view_top();
					stack.pop();
					secondOperand = stack.view_top();
					stack.pop();
					if (polish[i] == '+')
					{
						stack.push(firstOperand + secondOperand);
					}
					else if (polish[i] == '-')
					{
						stack.push(secondOperand - firstOperand);
					}
					else if (polish[i] == '*')
					{
						stack.push(secondOperand * firstOperand);
					}
					else if (polish[i] == '/')
					{
						stack.push(secondOperand / firstOperand);
					}
					else if (polish[i] == '^')
					{
						stack.push(pow(secondOperand, firstOperand));
					}
				}

			}
			else
			{
				firstOperand = stack.view_top();
				stack.pop();
				if (polish[i] == 's') // sin
				{
					stack.push(sin(firstOperand));
				}
				else if (polish[i] == 'c') // cos
				{
					stack.push(cos(firstOperand));
				}
				else if (polish[i] == 't') // tg
				{
					stack.push(sin(firstOperand) / cos(firstOperand));
				}
				else if (polish[i] == 'k') // ctg
				{
					stack.push(cos(firstOperand) / sin(firstOperand));
				}
				else if (polish[i] == 'q') //sqrt
				{
					stack.push(sqrt(firstOperand));
				}
			}

		}
	}
	double res = stack.view_top();
	return res;
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

void scan(string& input) {
	char c;
	cin >> c;
	while (c != '=') {
		input += c;
		cin >> c;
	}
}