/**
 * @file pr12-04.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program illustrates that you cannot compare
 *        C-strings with relational operators. Although it
 *        appears to test the strings for eqaulity, that is
 *        not what happens.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    // Two arrays for holding two strings
    const int LENGTH = 40;
    char firstString[LENGTH], secondString[LENGTH];

    // Read two strings
    cout << "Enter a string: ";
    cin.getline(firstString, LENGTH);
    cout << "Enter another string: ";
    cin.getline(secondString, LENGTH);

    // Attempt to compare the two strings using ==
    if (firstString == secondString)
    {
        cout << "You entered the same string twice.\n";
    }
    else
    {
        cout << "The strings are not the same.\n";
    }
        
    return 0;
}