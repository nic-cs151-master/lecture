#include <iostream>
#include "charstack.h"

using namespace std;

int main()
{
    CharStack myStack;

    myStack.push('C');
    myStack.push('E');
    myStack.push('F');
    myStack.push('V');

    cout << myStack.top() << '\n';

    if (!myStack.isEmpty())
        myStack.pop();

    myStack.top() = 'R';
    cout << myStack.top() << '\n';

    return 0;
}