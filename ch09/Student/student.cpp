#include "student.h"

// function definitions
// function definitions of all you class member functions

void display(const Student array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Name: " << array[i].name << '\n';
        cout << "ID: " << array[i].id << '\n';
        cout << "Age: " << array[i].age << '\n';
        cout << '\n';
    }
}