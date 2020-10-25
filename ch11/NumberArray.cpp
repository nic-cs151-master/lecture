#include <iostream>
#include "NumberArray.h" 
using namespace std;
 
/**
 * @brief Constructor allocates an array of the
 *        given size and sets all its entries to the
 *        given value.
 * 
 * @param size dynamic size of aPtr array
 * @param value the value of all the elements of aPtr
 */
NumberArray::NumberArray(int size, double value)
{
    arraySize = size;
    aPtr = new double[arraySize];
    setValue(value);
}

/**
 * @brief Sets all the entries of the array to the same value.
 * 
 * @param value assigns this value to all elements of aPtr
 */
void NumberArray::setValue(double value)
{
    for(int index = 0; index < arraySize; index++)
        aPtr[index] = value;
}

/**
 * @brief Prints all the entries of the array.
 */
void NumberArray::print() const
{
    for(int index = 0; index < arraySize; index++)
        cout << aPtr[index] << "  ";
}