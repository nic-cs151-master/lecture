#include "queue.h"

void Queue::enqueue(char x)
{
    if (isFull())
    {
        cout << "Queue is full!\n";
        return;
    }

    // mRear = -1
    mRear = (mRear + 1) % mCapacity;
    mQueue[mRear] = x;
    ++mSize;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        return;
    }

    // mFront = -1;
    mFront = (mFront + 1) % mCapacity;
    --mSize;
}

char& Queue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        exit(1);
    }

    return mQueue[(mFront + 1) % mCapacity];
}

char& Queue::back()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        exit(1);
    }
    return mQueue[mRear];
}

bool Queue::isEmpty()
{
    return mSize == 0;
}

bool Queue::isFull()
{
    return mSize == mCapacity;
}

Queue::Queue()
{
    mCapacity = 5;
    mQueue = new char[mCapacity];
    mFront = -1;
    mRear = -1;
    mSize = 0;
}

Queue::Queue(int queueSize)
{
    mCapacity = queueSize;
    mQueue = new char[mCapacity];
    mFront = -1;
    mRear = -1;
    mSize = 0;    
}
  
Queue::~Queue()
{
    delete [] mQueue;
}
