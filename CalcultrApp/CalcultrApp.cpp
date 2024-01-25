#include "Stack.h"
#include "functions.h"
#include <iostream>
#include <string>

enum { SIZE = 1000 };
using namespace std;

int main()
{
    string input = "";
    stack st(SIZE);
    string mod_input[1000];
    scan(input);
    delete_spaces(input);

    cout << input;



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