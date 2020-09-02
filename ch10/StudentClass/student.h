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

class Student
{
public:
    // constructors
    Student();
    Student(int id, string name, int age);

    // setters or mutators
    void setStudent(int id, string name, int age);
    void setId(int id);
    void setName(string name);
    void setAge(int age);

    // getters or accessors
    int getId() const;
    string getName() const;
    int getAge() const;

private:
    int m_id;
    string m_name;
    int m_age;
};

// display an array of students
void display(const Student array[], int size);
void sortByName(Student array[], int size);

#endif