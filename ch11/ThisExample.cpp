#include "ThisExample.h"
#include <iostream>
using namespace std; 

/**
 * @brief Set value of object
 * 
 * @param a 
 */
void Example::setValue(int a)
{
    x = a;
} 

/**
 * @brief Print address and value.
 * 
 */
void Example::printAddressAndValue()
{
    cout << "The object at address " << this << " has "
         << "value " << (*this).x << endl; 
}
