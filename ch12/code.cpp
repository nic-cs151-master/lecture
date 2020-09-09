#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str("Have a day");
    str.insert(7, "nice ");

    cout << str;

    // const int SIZE = 20;
    // char name[SIZE];

    // cout << "Enter a name: ";
    // cin.getline(name, SIZE);

    // cout << name << '\n';

    // istringstream iss;
    // string number;
    // int total, x;

    // cout << "Enter number: ";
    // cin >> number;

    // iss.str(number);

    // iss >> x;

    // total = x * x;
    // cout << "total = " << total << '\n';

    return 0;
}