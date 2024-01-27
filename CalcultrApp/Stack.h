#pragma once
#include <string>
using namespace std;

class stack {
public:
    stack() :top(0), arr(nullptr) {}
    stack(int len);
    ~stack();
    void push(string val);
    void pop();
    string view_top()const;
    int size()const;
    bool isEmpty()const;

private:
    int top;
    string* arr;

};