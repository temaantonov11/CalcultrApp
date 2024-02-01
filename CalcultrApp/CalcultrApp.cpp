#include "Stack.h"
#include "function.h"
#include "BigInt.h"
#include <iostream>
#include <string>
#include <vector>

enum { SIZE = 1000 };
using namespace std;

int main()
{
    string input = "";
    stack st(SIZE);
    string arr[1000];
    string variable_arr[10];
    double reso[1000];
    int point1 = 0;
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
        string res = Math(input, second_stack);
        if (res != "error")
            cout << "The answer: " << res << endl;
        else
            cout << "Error!";
    }
    else {
        while (start < size) {
            solve_variable(arr, size, start, point1, reso);
        }
        cout << "Answer: " << reso[point1 - 1];
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