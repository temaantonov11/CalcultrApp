#pragma once


class stack {
public:
    stack() :top(0), arr(nullptr) {}
    stack(int len);
    ~stack();
    void push(char val);
    void pop();
    char view_top()const;
    int size()const;
    bool isEmpty()const;

private:
    enum { SIZE = 100 };
    int top;
    char* arr;

};