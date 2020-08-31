#include <iostream>
#include "student.h"
using namespace std;

const int NUM_STUDENTS = 8;

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

    studs[3].name = "Barry";
    studs[3].id = 2982;
    studs[3].age = 19;

    studs[4].name = "Karen";
    studs[4].id = 723;
    studs[4].age = 32;

    studs[5].name = "Miko";
    studs[5].id = 123;
    studs[5].age = 27;

    studs[6].name = "Henry";
    studs[6].id = 812;
    studs[6].age = 20;

    studs[7].name = "Cindy";
    studs[7].id = 231;
    studs[7].age = 19;

    display(studs, NUM_STUDENTS);

    return 0;
}