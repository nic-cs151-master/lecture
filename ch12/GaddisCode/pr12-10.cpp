/**
 * @file pr12-10.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program uses a function to copy
 *        a string into an array.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std;

// Function prototype
void stringCopy(char destStr[], const char sourceStr[]);

int main() 
{
    // Define two arrays of char
    const int S_LENGTH = 30;
    char dest[S_LENGTH], source[S_LENGTH];

    // Read a string into a source array
    cout << "Enter a string with no more than "
         << S_LENGTH - 1 << " characters:\n";
    cin.getline(source, S_LENGTH);

    // Copy it into a destination array and print
    stringCopy(dest, source);
    cout << "The string you entered is:\n" << dest << endl;
    return 0;
}

void stringCopy(char destStr[], const char sourceStr[])
{
    const char *sPtr = sourceStr;
    char *dPtr = destStr;

    while (*sPtr != '\0')
    {
        *dPtr = *sPtr;
        ++dPtr;
        ++sPtr;
    }
    *dPtr = '\0';
}


/**
 * @brief This function accepts two character arrays as
 *        arguments. The function assumes the two arrays
 *        contain C-strings. The contents of the second
 *        array are copied to the first array
 * 
 * @param destStr   destination C-string
 * @param sourceStr source C-string 
 */
void stringCopy(char destStr[], const char sourceStr[]) 
{
    int index = 0;

    // Copy one character at a time till we come to 
    // the null terminator
    while (sourceStr[index] != '\0') 
    {
        destStr[index] = sourceStr[index];
        index++;
    }
    destStr[index] = '\0';
}