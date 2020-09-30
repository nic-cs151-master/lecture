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
    if (mHead == nullptr)
    {
        return;
    }

    ListNode *prevPtr = mHead;
    ListNode *nodePtr = mHead;

    while (nodePtr != nullptr)
    {
        if (nodePtr->value == number)
        {
            break;
        }
        prevPtr = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr)
    {
        return;
    }
    else if (nodePtr == prevPtr)
    {
        mHead = nodePtr->next;
        nodePtr->next = nullptr;
        delete nodePtr;
        nodePtr = nullptr;
    }
    else
    {
        prevPtr->next = nodePtr->next;
        nodePtr->next = nullptr;
        delete nodePtr;
        nodePtr = nullptr;
    }
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
    else
    {
        // recursive case
        cout << ptr->value << ' ';
        printList(ptr->next);
    }
}