/**
 * @file pr12-01.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates that string literals are
 *        pointers to char
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    // Define variables that are pointers to char
    const char *p = nullptr, *q = nullptr;

    // Assign string literals to the pointers to char
    p = "Hello ";
    q = "Bailey";

    // Print the pointers as C-strings!
    cout << p << q << endl;

    int x;
    int* ptr = new int;
    int* ptr2 = new int;

    // Print the pointers as C-strings and as addresses
    cout << &x << endl;
    cout << p  << " is stored at " << reinterpret_cast<const void*>(p) << endl;
    cout << q  << " is stored at " << reinterpret_cast<const void*>(q) << endl;
    cout << "ptr is stored at " << &ptr << " and points to " << ptr << endl;
    cout << "ptr2 is stored at " << &ptr2 << " and points to " << ptr2 << endl;

    // A string literal can be treated as a pointer!
    //    cout << "String literal stored at " << long("literal");
    return 0;
}