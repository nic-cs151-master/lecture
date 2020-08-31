#include "student.h"

// function definitions
// function definitions of all you class member functions

void display(const Student array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << setw(6) << right << array[i].id   << ' '
             << setw(8) << left  << array[i].name << ' '
             << setw(4) << right << array[i].age  << '\n';
    }
}