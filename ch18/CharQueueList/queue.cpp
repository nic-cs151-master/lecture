#include "queue.h"

void Queue::enqueue(char x)
{
    // add to mRear
    if (mRear == nullptr)
    {
        mFront = mRear = new Node(x, mRear);
    }
    else
    {
        /* code */
        mRear->next = new Node(x);
        mRear = mRear->next;
    }
    ++mSize;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node *ptr = mFront;
    mFront = mFront->next;
    ptr->next = nullptr;
    delete ptr;
    ptr = nullptr;
    --mSize;
}

char& Queue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        exit(1);
    }

    return mFront->data;
}

char& Queue::back()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        exit(1);
    }
    return mRear->data;
}

bool Queue::isEmpty()
{
    return mSize == 0;
}

Queue::Queue()
{
    mFront = mRear = nullptr;
    mSize = 0;
}
  
Queue::~Queue()
{
    // delete [] mQueue;
}
