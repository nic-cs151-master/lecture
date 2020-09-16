/**
 * @file pr13-01.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program demonstrates reading and writing 
 *        a file through an fstream object
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // ifstream ofstream
    fstream inOutFile;
    string word;         // Used to read a word from the file

    // Open the file
    inOutFile.open("inout.txt");
    if (!inOutFile)
    {
        cout << "The file was not found." << endl;
        return 1;
    }

    // Read and print every word already in the file   
    while (inOutFile >> word)
    {
        cout << word << endl;
    }

    // Clear end of file flag to allow additional file operations
    inOutFile.clear();

    // Write a word to the file and close the file
    inOutFile << "World" << endl;
    inOutFile.close();    

    return 0;
}