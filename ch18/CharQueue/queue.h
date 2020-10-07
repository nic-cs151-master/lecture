#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
public:
    void enqueue(char x);
    void dequeue();
    char& front();
    char& back();
    bool isEmpty();
    bool isFull();
    Queue();
    Queue(int queueSize);  
    ~Queue();

private:
    char *mQueue;  // for the array
    int mCapacity, mFront, mRear, mSize;
};

#endif