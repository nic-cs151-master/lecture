#ifndef CHAR_STACK
#define CHAR_STACK

#include <iostream>
#include <cstdlib>
using namespace std;

class CharStack
{
public:
    CharStack();
    CharStack(int stackSize);  
    ~CharStack();

    void push(char x);
    void pop();
    char& top();
    bool isEmpty();
    bool isFull();

private:
    char *mStackArray;  // for the array
    int mCapacity, mTop;
};

#endif