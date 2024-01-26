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
    string arr[1000];
    int size = 0;

    scan(input);
    delete_spaces(input);
    string_to_array(input, arr, size);

    for (int i = 0; i < size; ++i) {
        cout << "[ " << arr[i] << " ] ";
    }
    cout << endl << polish_natation(arr, size, st);


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