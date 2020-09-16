/**
 * @file pr13-03.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates input and output of numbers
 *        using the octal, decimal, and hexademical number systems.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{    
    int a, b;
    // Read two decimals and print hex and octal equivalents
    cout << "Enter two decimal numbers: ";
    cin >> a >> b;
    cout << "The numbers in decimal: " << a << '\t' << b << endl;    
    cout << "The numbers in hexadecimal: " <<  hex 
         << showbase << a << '\t' << b << endl;    
    cout << "The numbers in octal: " << oct 
         <<  a << '\t' << b << endl;
    
    // Read some hexadecimals and print their decimal equivalents
    cout << "Enter two hexadecimal numbers: ";
    cin >> hex >> a >> b;
    cout << "You entered decimal " << dec 
         << a << '\t' << b << endl;
    
    // Read some octals and print their decimal equivalents
    cout << "Enter two octal numbers: ";
    cin >> oct >>  a >> b;
    cout << "You entered decimal " << dec 
         << a << '\t' << b << endl; 
 
    return 0;
}