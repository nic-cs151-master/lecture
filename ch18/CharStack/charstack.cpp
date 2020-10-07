#include "charstack.h"

CharStack::CharStack()
{
    mStackArray = new char[10];
    mCapacity = 10;
    mTop = 0;
}

CharStack::CharStack(int stackSize)
{
    mStackArray = new char[stackSize];
    mCapacity = stackSize;
    mTop = 0;
}

CharStack::~CharStack()
{
    delete [] mStackArray;
}


void CharStack::push(char x)
{
    if (isFull())
    {
        cout << "Stack is full!\n";
        return;
    }

    mStackArray[mTop++] = x;
    // ++mTop;
}

void CharStack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty! No bueno!\n";
        return;
    }
    mStackArray[mTop] = '\0';
    --mTop;
}

char& CharStack::top()
{
    if (isEmpty())
    {
        cout << "Stack is empty! No bueno!\n";
        exit(1);
    }

    return mStackArray[mTop - 1];
}

bool CharStack::isEmpty()
{
    return mTop == 0;
}

bool CharStack::isFull()
{
    return mTop == mCapacity;
}
