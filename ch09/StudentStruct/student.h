// Guard
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// constant global variables

// function prototypes
// class declarations
// struct declarations

struct Student
{
    int id;
    string name;
    int age;
};

// display an array of students
void display(const Student array[], int size);

#endif