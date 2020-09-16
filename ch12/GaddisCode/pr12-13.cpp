/**
 * @file pr12-13.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates the use of the string find
 *        and insert member functions. To make a dollar value
 *        easier to read, it add the dollar $ symbol and add
 *        commas to the number if necessary.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
  #include <iostream>
  #include <string>
  using namespace std;
  
  // Function prototype
  string dollarFormat(string original);  
  
  int main(void)
  {
     string input;    // User input
 
     // Get the dollar amount from the user
     cout << "Enter a dollar amount in the form nnnnn.nn : ";
     cin >> input;
 
     // Display the formatted dollar amount
     cout << "Formatted amount:   " <<  dollarFormat(input) << endl;
     return 0;
 }
 
 //******************************************************
 // Returns a $-formatted version of the input string.  *
 //******************************************************
 /**
  * @brief Returns a $-formatted version of the input string.
  * 
  * @param original original string value
  * @return string  $-formatted version of original
  */
 string dollarFormat(string original)
 {
     string formatted = original;
     int dp = formatted.find('.');  // Position of decimal point
     int pos = dp;                  // Search for comma position
     while (pos > 3)
     {
        pos = pos - 3;
        formatted.insert(pos, ",");
     }
     formatted.insert(0, "$");
     return formatted;
 }
