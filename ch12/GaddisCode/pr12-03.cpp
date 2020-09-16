/**
 * @file pr12-03.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program illustrates dynamic allocation
 *        of storage for C-strings.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>  
using namespace std;

int main()
{
    const int NAME_LENGTH = 50;     // Maximum length  	 
    char *pname = nullptr;          // Address of array
	             
    // Allocate the array
    pname = new char[NAME_LENGTH];    
	 
    // Read a string    
    cout << "Enter your name: ";
    cin.getline(pname, NAME_LENGTH);      
	 
    // Display the string           
    cout << "Hello " << pname;
	
	// Release the memory
	delete [] pname;
    	
    return 0;
}