/**
 * @file pr13-02.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates the use of an ostringstream
 *        object to do sophisticated formatting.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

string dollarFormat(double); // Function Prototype
  
int main()
{
    const int ROWS = 3, COLS = 2;
    double amount[ROWS][COLS] = {184.45,    7, 59.13, 
                                  64.32, 7.29,  1289 };

    // Format table of dollar amounts  right justfied 
    // in columns of width 10
    cout << right;
    for (int row = 0; row< ROWS; row++)
    { 
        for (int column = 0; column < COLS; column++)
        {
            cout << setw(10)
                 << dollarFormat(amount[row][column]);
        }
        cout << endl;
    }

    return 0;
 }
 
 /**
  * @brief Formats a dollar amount
  * 
  * @param amount 
  * @return string 
  */
string dollarFormat(double amount)
{
    // Create ostringstream object
    ostringstream outStr;  

    // Set up format information and write to outStr.
    outStr << showpoint << fixed << setprecision(2);
    outStr << '$' << amount;

    // Extract and return the string inside outStr.
    return outStr.str();
}
