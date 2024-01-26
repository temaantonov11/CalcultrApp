#pragma once

class doubleStack
{
public:
	doubleStack() : arr(nullptr), top(0) {}
	doubleStack(int len);
	~doubleStack();
	void push(double val);
	void pop();
	double view_top()const;
	int size()const;
	bool isEmpty()const;

	
private:
	double* arr;
	int top;
};