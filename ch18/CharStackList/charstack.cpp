#include "charstack.h"

CharStack::CharStack()
{
    mTop = nullptr;
    mSize = 0;
}

CharStack::~CharStack()
{
    // delete [] mStackArray;
}


void CharStack::push(char x)
{
    mTop = new Node(x, mTop);
    ++mSize;
}

void CharStack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty! No bueno!\n";
        return;
    }

    Node *ptr = mTop;
    mTop = mTop->next;
    ptr->next = nullptr;
    delete ptr;
    ptr = nullptr;
    --mSize;
}

char& CharStack::top()
{
    char x = 'a';
    if (isEmpty())
    {
        cout << "Stack is empty! No bueno!\n";
        exit(1);
    }

    return mTop->data;
}

bool CharStack::isEmpty()
{
    return mTop == nullptr;
}


