#include "doubleStack.h"
#include <iostream>
#include <stdexcept>

doubleStack::doubleStack(int len)
{
	this->arr = new double[len];
}

doubleStack::~doubleStack()
{
	if (arr)
		delete[] arr;
}

void doubleStack::push(double val)
{
	this->arr[this->top] = val;
	this->top++;
}

double doubleStack::view_top()const
{
	return this->arr[this->top - 1];
}

int doubleStack::size()const
{
	return this->top;
}

bool doubleStack::isEmpty()const
{
	if (this->top == 0)
		return true;
	return false;
}

void doubleStack::pop()
{
	if (doubleStack::isEmpty())
		throw std::length_error("doubleStack is empty!");
	this->top--;
}