﻿#include "Stack.h"
#include <iostream>
#include <string>

enum { SIZE = 100 };
using namespace std;

int main()
{
    stack st(SIZE);
    
    try
    {
        cout << "1122";
    }
    catch (const std::length_error ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}