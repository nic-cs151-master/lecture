/**
 * @file pr12-12.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates a function, countChars,
 *        that counts the number of times a specific
 *        character appears in a string.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std; 

// Function prototype
int countChars(const char *strPtr, char ch);

int main() 
{
    // Define array to hold the string
    const int S_LENGTH = 51;
    char userString[S_LENGTH];

    char letter; // User input

    // Read the string and the letter to count
    cout << "Enter a string (up to "
         << S_LENGTH - 1 << " characters): ";
    cin.getline(userString, S_LENGTH);
    cout << "Enter a character and I will tell you how many\n";
    cout << "times it appears in the string: ";
    cin >> letter;

    // Output the results of the letter count
    cout << letter << " appears ";
    cout << countChars(userString, letter) << " times.\n";
    return 0;
}

/**
 * @brief The function returns the number of times the
 *        character ch appears in the string pointed by
 *        strPtr.
 * 
 * @param strPtr pointer to a C-string
 * @param ch     character to search for
 * @return int   number of times ch appears in string
 */
int countChars(const char *strPtr, char ch) 
{
    int count = 0;
    while (*strPtr != '\0') 
    {
        if (*strPtr == ch)
            count++;
        strPtr++;
    }
    return count;
}