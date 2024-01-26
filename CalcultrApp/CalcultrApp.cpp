#include "Stack.h"
#include "doubleStack.h"
#include <iostream>
#include <string>


enum { SIZE = 100 };

using namespace std;

int main()
{
    doubleStack s1(SIZE);
    s1.push(2.3);
    s1.push(4.2);
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.view_top() << endl;
    s1.pop();
    cout << s1.size();
    
    try
    {

    }
    catch (const std::length_error ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}