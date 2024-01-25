#include "Stack.h"
#include "functions.h"
#include <iostream>
#include <string>

enum { SIZE = 100 };
using namespace std;

int main()
{
    string input = "";
    stack st(SIZE);
    scan(input);
    delete_spaces(input);
    polish_natation(input, st);
    cout << st.view_top();



    /*try
    {

    }
    catch (const std::length_error ex)
    {
        std::cerr << ex.what() << '\n';
    }
    */
    return 0;
}