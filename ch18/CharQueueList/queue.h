#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(){}
    Node(char d, Node *n=nullptr)
    {
        data = d;
        next = n;
    }
};

class Queue
{
public:
    void enqueue(char x);
    void dequeue();
    char& front();
    char& back();
    bool isEmpty();
    Queue();
    ~Queue();

private:
    Node *mFront;  // for the array
    Node *mRear;
    int mSize;
};

#endif