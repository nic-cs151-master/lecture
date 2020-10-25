/**
 * @file pr11-06.cpp
 * This program demonstrates the operation of the
 * default copy constructor.
 * @author: Gaddis
 */
#include <iostream>
#include <string> 
using namespace std;

class Address
{
public:
    Address() { street = ""; }
    Address(string st) { setStreet(st); }
    void setStreet(string st) { street = st; }
    string getStreet() const { return street; } 

private:
    string street;   
};

int main()
{
    // Mary and Joan live at same address
    Address mary("123 Main St");
    Address joan = mary;
    // joan.street = mary.street
    cout << "Mary lives at " << mary.getStreet() << endl;
    cout << "Joan lives at " << joan.getStreet() << endl;

    // Now Joan moves out
    joan.setStreet("1600 Pennsylvania Ave");
    cout << "Now Mary lives at " << mary.getStreet() << endl;
    cout << "Now Joan lives at " << joan.getStreet() << endl;

    return 0;
}    