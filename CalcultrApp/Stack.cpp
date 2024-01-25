#include "Stack.h"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
stack::stack(int len)
{
    this->top = 0;
    this->arr = new string[len];
}

stack::~stack()
{
    if (arr)
        delete[] arr;
}

void stack::push(string val)
{
    this->arr[this->top] = val;
    this->top++;
}

string stack::view_top()const
{
    return this->arr[this->top - 1];
}

int stack::size()const
{
    return this->top;
}

bool stack::isEmpty()const
{
    if (this->top == 0)
        return true;
    return false;
}

void stack::pop()
{
    if (stack::isEmpty())
        throw std::length_error("Stack is empty");
    this->top--;
}