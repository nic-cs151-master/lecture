#include "linkedlist.h"

LinkedList::LinkedList()
{
    mHead = nullptr;
    mSize = 0;
}

LinkedList::~LinkedList()
{
    // if it is not empty, delete all the nodes
}

void LinkedList::add(double number)
{
    // add always at the end of list
    // list is empty
    if (mHead == nullptr)
    {
        mHead = new ListNode(number);
    }
    else // not empty
    {
        ListNode *nodePtr = mHead;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = new ListNode(number);
    } 
    ++mSize;
}

string LinkedList::toString()
{
    if (mHead == nullptr)
        return "";

    ostringstream ostr;
    ListNode *nodePtr = mHead;
    while (nodePtr != nullptr)
    {
        ostr << nodePtr->value << ' ';
        nodePtr = nodePtr->next;
    }
    return ostr.str();
}

unsigned int LinkedList::size() const
{
    return mSize;
}

void LinkedList::remove(double number)
{
    // list is empty
    if (mHead == nullptr)
    {
        return;
    }

    ListNode *prevPtr = nullptr; // previous node pointer
    ListNode *curPtr = mHead;    // current node pointer

    while (curPtr != nullptr)
    {
        if (curPtr->value == number)
        {
            break;
        }
        prevPtr = curPtr;
        curPtr = curPtr->next;
    }

    // not found
    if (curPtr == nullptr)
    {
        return;
    }
    // item found at the head node
    else if (prevPtr == nullptr)
    {
        mHead = curPtr->next;
    }
    // item found besides the head node
    else
    {
        prevPtr->next = curPtr->next;
    }

    curPtr->next = nullptr;
    delete curPtr;
    curPtr = nullptr;
}

void LinkedList::toString2()
{
    printList(mHead);
    cout << '\n';
}

void LinkedList::printList(ListNode* ptr)
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else  // recursive case
    {
        cout << ptr->value << ' ';
        printList(ptr->next);
    }
}