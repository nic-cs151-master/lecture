/**
 * @file pr11-05.cpp
 * This program demonstrates object assignment.
 * @author: Gaddis
 */
#include <iostream>
using namespace std; 

class Rectangle
{
public:
    Rectangle(double width, double length)
    {
        this->width = width;
        this->length = length;
    }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    void output() const
    {
        cout << "Width is " << width << ", "
             << "Length is " << length << endl;
    }

private:
    double width, length;
};

int main()
{
    // Set up two rectangle objects
    Rectangle box1(10, 20), box2(5, 10);  

    // Display the rectangle objects
    cout << "Before the assignment:\n";
    cout << "Box 1 data:\t";  box1.output();
    cout << "Box 2 data:\t";  box2.output();

    // Assignment
    box2 = box1;
    // box2.width = box1.width
    // box2.length = box1.length

    // Display the rectangle objects
    cout << "\nAfter the assignment:\n";
    cout << "Box 1 data:\t"; box1.output();
    cout << "Box 2 data:\t"; box2.output();  
    return 0;
}