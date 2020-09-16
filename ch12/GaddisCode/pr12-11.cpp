/**
 * @file pr12-11.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program uses the function nameSlice
 *        to "cut" off the last name of a string that
 *        contains the user's first and last names.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std; 

void nameSlice(char userName[]); // Function prototype

int main() 
{
    // Define array of char to hold name
    const int NAME_LENGTH = 41;
    char name[NAME_LENGTH];

    // Get user's first and last names
    cout << "Enter your first and last names, separated ";
    cout << "by a space:\n";
    cin.getline(name, NAME_LENGTH);

    // Slice off the last name and print what is left
    nameSlice(name);
    cout << "Your first name is: " << name << endl;
    return 0;
}

/**
 * @brief This function accepts a character array as its
 *        argument. It scans the array looking for a space.
 *        When it finds one, it replaces it with a null
 *        character.
 * 
 * @param userName array of characters
 */
void nameSlice(char userName[]) 
{
    // Look for the end of the first name, indicated
    // by a space or a null terminator
    int k = 0;
    while (userName[k] != ' ' && userName[k] != '\0')
        k++;

    // Insert null terminator	
    if (userName[k] == ' ')
        userName[k] = '\0';
}