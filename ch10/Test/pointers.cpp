#include <iostream>
using namespace std;

int main()
{
    int x = 25;          // int variable
    int* ptr = nullptr;  // pointer variable

    ptr = &x;

    // cout << "x = " << x << '\n';
    // cout << "&x = " << &x << '\n';
    // cout << "x has " << sizeof(x) << " bytes\n";

    // cout << "the value in x is " << x << '\n';
    // cout << "the address of x is " << &x << '\n';
    // cout << "the value in ptr is " << ptr << '\n';
    // cout << "the address of ptr is " << &ptr << '\n';
    // cout << "the value in the address pointed by ptr is " << *ptr << '\n';

    int numbers[] = {10, 20, 30, 40, 50};
    cout << numbers << '\n';

    return 0;
}