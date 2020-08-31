#include "student.h"

void sortByName(Student array[], int size)
{
    for (int startScan = 1; startScan < size; ++startScan)
    {
        Student key = array[startScan];
        int index = startScan - 1;

        while (index >= 0 && array[index].getName() > key.getName())
        {
            array[index+1] = array[index];
            --index;
        }
        array[index+1] = key;
    }
}

void display(const Student array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << setw(6) << right << array[i].getId()   << ' '
             << setw(8) << left  << array[i].getName() << ' '
             << setw(4) << right << array[i].getAge()  << '\n';
    }
}

// constructors
Student::Student()
{
    m_id = 0;    // default value is zero
    m_name = ""; // default value is an empty string
    m_age = 0;   // default value is zero
}

Student::Student(int id, string name, int age)
{
    setStudent(id, name, age);
}

// setters or mutators
void Student::setStudent(int id, string name, int age)
{
    m_id = id;
    m_name = name;
    m_age = age;
}

void Student::setId(int id)
{
    m_id = id;
}

void Student::setName(string name)
{
    m_name = name;
}

void Student::setAge(int age)
{
    m_age = age;
}

// getters or accessors
int Student::getId() const
{
    return m_id;
}

string Student::getName() const
{
    return m_name;
}

int Student::getAge() const
{
    return m_age;
}