#include "sortedlinkedlist.h"


void SortedLinkedList::add(double number)
{
    if (mHead == nullptr || number < mHead->value)
    {
        mHead = new ListNode(number, mHead);
    }
    else
    {
        ListNode *nodePtr = new ListNode(number);
        ListNode *curPtr = mHead;

        while (curPtr->next != nullptr && curPtr->next->value < number)
        {
            curPtr = curPtr->next;
        }

        nodePtr->next = curPtr->next;
        curPtr->next = nodePtr;
    }
}