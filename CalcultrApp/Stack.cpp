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

int stack::size()const
{
    return top;
}

bool stack::isEmpty()const
{
    if (this->top == 0)
        return true;
    return false;
}

string stack::pop()
{
    if (stack::isEmpty())
        return "@@@";
    this->top--;
    return this->arr[this->top];
}