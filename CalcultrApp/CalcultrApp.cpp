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
    string variable_arr[10];
    string variable_value[10];
    int point = 0;
    int size = 0;
    int start = 0;

    cout << "Please write an expression or a function:" << endl;
    scan(input);
    delete_spaces(input);
    while (check(input)) {
        input = "";
        scan(input);
        delete_spaces(input);
    }
    string_to_array(input, arr, size);
    if ((point = count_variable(arr, size, variable_arr)) == 0) {
        input = polish_natation(arr, size, st);
        stack second_stack(SIZE);
        double res = Math(input, second_stack);
        cout << "The answer: " << res;
    }
    else {
        set_positions(arr, size, variable_arr, variable_value, point, start);
        fill_array(arr, size, variable_arr, variable_value, point);
        edit_array(arr, size, start);
        input = polish_natation(arr, size, st);
        stack second_stack(SIZE);
        double res = Math(input, second_stack);
        cout << "The answer: " << res;

    }
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