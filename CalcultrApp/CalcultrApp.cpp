#include "Stack.h"
#include "function.h"
#include <iostream>
#include <string>

enum { SIZE = 1000 };
using namespace std;

int main()
{
    string input = "";
    stack st(SIZE);
    string arr[1000];
    int size = 0;

    cout << "Please write an expression or a function:" << endl;
    scan(input);
    delete_spaces(input);
    while (check(input)) {
        input = "";
        scan(input);
        delete_spaces(input);
    }
    string_to_array(input, arr, size);
    input = polish_natation(arr, size, st);
    stack second_stack(SIZE);
    double res = Math(input, second_stack);
    cout << "The answer: " << res;

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