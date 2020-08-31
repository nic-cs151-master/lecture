#include <iostream>
#include "student.h"
using namespace std;

const int NUM_STUDENTS = 8;

int main()
{
    Student studs[NUM_STUDENTS] = {Student(1001, "John", 21),
                                   Student(982, "Jane", 30),
                                   Student(328, "Joe", 18),
                                   Student(2982, "Barry", 19),
                                   Student(723, "Karen", 32),
                                   Student(123, "Miko", 27),
                                   Student(812, "Henry", 20),
                                   Student(231, "Cindy", 19)};


    cout << "Before sorting:\n";
    display(studs, NUM_STUDENTS);
    sortByName(studs, NUM_STUDENTS);

    cout << "After sorting:\n";
    display(studs, NUM_STUDENTS);

    return 0;
}