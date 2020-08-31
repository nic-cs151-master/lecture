#include <iostream>
#include "student.h"
using namespace std;

const int NUM_STUDENTS = 3;

int main()
{
    Student studs[NUM_STUDENTS];

    // John, Jane, Joe
    studs[0].name = "John";
    studs[0].id = 1001;
    studs[0].age = 21;

    studs[1].name = "Jane";
    studs[1].id = 982;
    studs[1].age = 30;

    studs[2].name = "Joe";
    studs[2].id = 328;
    studs[2].age = 18;

    display(studs, NUM_STUDENTS);

    return 0;
}